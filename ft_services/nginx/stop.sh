#!/bin/bash

kubectl ns default
kubectl delete deployment wildboar-nginx-depl
kubectl delete service wildboar-nginx-service
kubectl ns metallb-system
kubectl delete configmap metallb.configmap
kubectl ns default
docker rmi -f wildboar.nginx
minikube stop
