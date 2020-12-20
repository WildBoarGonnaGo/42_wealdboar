# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 19:15:48 by lchantel          #+#    #+#              #
#    Updated: 2020/12/20 23:44:28 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -U -a upgrade
RUN apk add vsftpd openrc openssl lftp linux-pam apache2-utils shadow linux-pam
RUN openssl req -new -x509 -days 1461 -nodes -out /etc/ssl/certs/vsftpd.pem \
-keyout /etc/ssl/private/vsftpd.key \
-subj "/C=RU/ST=Moscow/L=Moscow/O=21-school/CN=192.168.99.105/CN=ftp"
COPY ./vsftpd.conf /etc/vsftpd/
RUN echo -e "ftpuser\nftpuser" | useradd ftpuser -d /ftp -s /bin/false -m
RUN echo "/bin/false" >> /etc/shells
RUN htpasswd -cbd /etc/vsftpd/ftpd.passwd virt1 virt1
RUN htpasswd -bd /etc/vsftpd/ftpd.passwd virt2 virt2
RUN mkdir -p /etc/vsftpd_virtuser_conf/
RUN useradd vsftpd -d /home/vsftpd -g nogroup -m -s /bin/false
RUN mkdir -p /var/www/virt1
RUN chown vsftpd:nogroup /var/www/virt1
COPY ./virt1 /etc/vsftpd_virtuser_conf/
COPY ./vsftpd /etc/pam.d/
COPY ./ftps_launch.sh /
RUN chmod 755 ./ftps_launch.sh
EXPOSE 21
#RUN rc-update add vsftpd default
#RUN rc-service vsftpd stop
CMD /ftps_launch.sh
#["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"] 
#/bin/sh


