# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 19:15:48 by lchantel          #+#    #+#              #
#    Updated: 2020/12/27 17:49:32 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -U -a upgrade
RUN apk add vsftpd openssl shadow
RUN openssl req -new -x509 -days 1461 -nodes -out /etc/ssl/certs/vsftpd.crt \
-keyout /etc/ssl/private/vsftpd.key \
-subj "/C=RU/ST=Moscow/L=Moscow/O=21-school/CN=192.168.99.105/CN=ftp"
COPY ./vsftpd.conf /etc/vsftpd/
RUN mkdir -p /home/wildboar/
RUN mkdir /2ch.hk
RUN echo -e "wildboar\nwildboar\n" | adduser wildboar
RUN chown wildboar:wildboar /home/wildboar/
#COPY ./virt1 /etc/vsftpd_virtuser_conf/
#COPY ./vsftpd /etc/pam.d/
COPY ./ftps_launch.sh /
RUN chmod 755 ./ftps_launch.sh
EXPOSE 21 21000
#RUN rc-update add vsftpd default
#RUN rc default
CMD /ftps_launch.sh
#["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"] 
#/bin/sh


