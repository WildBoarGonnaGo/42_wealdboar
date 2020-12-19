# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 19:15:48 by lchantel          #+#    #+#              #
#    Updated: 2020/12/19 16:12:15 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -U -a upgrade
RUN apk add vsftpd supervisor openrc openssl lftp
RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 -subj \
"/C=RU/ST=Moscow/L=Moscow/O=lchantel/CN=localhost" -keyout \
/etc/ssl/private/wildboar.key -out /etc/ssl/certs/wildboar.crt
COPY ./vsftpd.conf /etc/vsftpd/
#COPY ./supervisord.conf ./etc/ 
EXPOSE 21
RUN rc-update add vsftpd default
#RUN rc-service vsftpd stop
CMD rc default && sh
#["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"] 
#/bin/sh
