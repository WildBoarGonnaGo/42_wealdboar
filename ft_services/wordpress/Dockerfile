# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 11:18:44 by lchantel          #+#    #+#              #
#    Updated: 2020/12/01 17:31:11 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -U -a upgrade
RUN apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli \
php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt \
php7-gettext php7-ldap php7-ctype php7-dom openrc 
COPY ./lighttpd.conf /etc/lighttpd/
COPY ./repositories /etc/apk/
RUN mkdir -p /usr/share/webapps
RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz 
RUN cp -R wordpress /usr/share/webapps
RUN mv wordpress /var/www/
RUN rm latest.tar.gz
RUN chown -R lighttpd /usr/share/webapps/
RUN chown -R lighttpd /var/www/
RUN ln -s /usr/share/webapps/wordpress/ /var/www/localhost/wordpress
EXPOSE 5050
