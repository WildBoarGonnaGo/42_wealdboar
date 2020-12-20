#!/bin/bash

minikube delete 
minikube start --driver=virtualbox --disk-size='5000mb' --memory='3072mb'
minikube addons enable metallb
eval $(minikube docker-env)
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
docker build -t wildboar.nginx ./nginx/
docker build -t wildboar.mysql ./mysql/
docker build -t wildboar.phpmyadmin ./phpmyadmin/
docker build -t wildboar.wordpress ./wordpress/
docker build -t wildboar.ftps ./ftps 
kubectl apply -f ./wildboarlb.yaml
kubectl apply -f ./nginx/wildboar.nginx.yaml
kubectl apply -f ./ftps/wildboar.ftps.deploy.yaml
kubectl apply -f ./mysql/wildboar.mysql.deploy.yaml
kubectl apply -f ./phpmyadmin/wildboar.phpmyadmin.deploy.yaml
kubectl apply -f ./wordpress/wildboar.wordpress.deploy.yaml
minikube dashboard
