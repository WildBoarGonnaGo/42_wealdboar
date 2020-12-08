#!/bin/bash

kubectl ns default
kubectl delete deployment --all
kubectl delete service --all
kubectl ns metallb-system
kubectl delete configmap --all
kubectl ns default
docker rmi -f wildboar.nginx
minikube stop
minikube delete 
minikube start --driver=virtualbox --disk-size='5000mb' --memory='3072mb'
minikube addons enable metallb
eval $(minikube docker-env)
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
#kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
docker build -t wildboar.nginx .
kubectl apply -f ../wildboarlb.yaml
kubectl apply -f ./wildboar.nginx.yaml
