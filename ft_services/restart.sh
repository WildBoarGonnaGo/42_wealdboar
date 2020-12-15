#!/bin/bash

minikube delete 
minikube start --driver=virtualbox --disk-size='5000mb' --memory='3072mb'
minikube addons enable metallb
eval $(minikube docker-env)
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
docker build -t wildboar.nginx /home/lchantel/42-wildboar-git/ft_services/nginx/
docker build -t wildboar.mysql /home/lchantel/42-wildboar-git/ft_services/mysql/
docker build -t wildboar.phpmyadmin /home/lchantel/42-wildboar-git/ft_services/phpmyadmin/
docker build -t wildboar.wordpress /home/lchantel/42-wildboar-git/ft_services/wordpress/
kubectl apply -f ./wildboarlb.yaml
kubectl apply -f ./nginx/wildboar.nginx.yaml
kubectl apply -f ./mysql/wildboar.mysql.pv-pvc.yaml
kubectl apply -f ./mysql/wildboar.mysql.deploy.yaml
kubectl apply -f ./phpmyadmin/wildboar.phpmyadmin.deploy.yaml
kubectl apply -f ./wordpress/wildboar.wordpress.deploy.yaml
minikube dashboard
