#!/bin/bash

minikube delete 
minikube start --driver=virtualbox --disk-size='5000mb' --memory='3072mb'
minikube addons enable metallb
minikube addons enable metrics-server
eval $(minikube docker-env)
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
docker build -t nginx ./srcs/nginx/
docker build -t mysql ./srcs/mysql/
docker build -t phpmyadmin ./srcs/phpmyadmin/
docker build -t wordpress ./srcs/wordpress/
docker build -t ftps ./srcs/ftps/
docker build -t influxdb ./srcs/influxdb
docker build -t grafana ./srcs/grafana
kubectl apply -f ./srcs/metallb.yaml
kubectl apply -f ./srcs/nginx/nginx.yaml
kubectl apply -f ./srcs/ftps/ftps.yaml
kubectl apply -f ./srcs/mysql/mysql.yaml
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f ./srcs/wordpress/wordpress.yaml
kubectl apply -f ./srcs/influxdb/influxdb.yaml
kubectl apply -f ./srcs/grafana/grafana.yaml
rm -f ~/.ssh/known_hosts/
minikube dashboard
