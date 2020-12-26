# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 20:31:22 by lchantel          #+#    #+#              #
#    Updated: 2020/12/26 00:57:11 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -a -U upgrade
RUN apk add nginx php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi \ 
fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype \
php7-dom tar openrc supervisor php7-fpm php7-session openssl
#RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 -subj \
#"/C=RU/ST=Moscow/L=Moscow/O=lchantel/CN=localhost" -keyout \
#/etc/ssl/private/lchantel.key -out /etc/ssl/certs/lchantel.crt
RUN adduser -D -g 'www' www
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar -xzf phpMyAdmin-5.0.4-english.tar.gz
COPY ./supervisord.conf /etc/
COPY ./default.conf /etc/nginx/conf.d/
COPY ./www.conf /etc/php7/php-fpm.d/
COPY ./nginx.conf /etc/nginx/
RUN mv /phpMyAdmin-5.0.4-english/ /var/www/phpmyadmin/
COPY ./config.inc.php /var/www/phpmyadmin/
EXPOSE 5000
RUN rc default && rc-service nginx start && rc-service php-fpm7 start
RUN rc-service nginx stop && rc-service php-fpm7 stop
RUN chown -R www:www /var/www/
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
