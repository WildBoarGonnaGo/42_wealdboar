# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 20:31:22 by lchantel          #+#    #+#              #
#    Updated: 2020/12/02 20:49:21 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -a -U upgrade
RUN apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi \ 
fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype \
php7-dom tar openrc
COPY ./lighttpd.conf /etc/lighttpd/lighttpd.conf
RUN mkdir /usr/share/webapps
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar -xvzf phpMyAdmin-5.0.4-english.tar.gz
RUN cp -R phpMyAdmin-5.0.4-english /var/www/phpmyadmin
RUN mv phpMyAdmin-5.0.4-english /usr/share/webapps/phpmyadmin
RUN rm -rf phpMyAdmin-5.0.4-english.tar.gz
RUN chmod -R 777 /usr/share/webapps/
EXPOSE 5000
CMD rc-update add lighttpd default && rc default 
# && /bin/sh
