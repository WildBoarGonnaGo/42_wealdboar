# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 11:18:44 by lchantel          #+#    #+#              #
#    Updated: 2020/12/26 00:56:23 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -U -a upgrade
RUN apk add nginx php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli \
php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt \
php7-gettext php7-ldap php7-ctype php7-dom openrc php7-session php7-fpm supervisor openssl
#RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 -subj \
#"/C=RU/ST=Moscow/L=Moscow/O=lchantel/CN=localhost" -keyout \
#/etc/ssl/private/lchantel.key -out /etc/ssl/certs/lchantel.crt
RUN adduser -D -g 'www' www   
VOLUME /var/lib/mysql/
COPY ./repositories /etc/apk/
RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzf latest.tar.gz 
RUN mv wordpress /var/www/
RUN rm latest.tar.gz
RUN rm -rf latest/
RUN mkdir -p /var/www/html/
RUN mkdir -p /var/www/wordpress/wp-content/mu-plugins/
COPY ./supervisord.conf /etc/
COPY ./default.conf /etc/nginx/conf.d/
COPY ./www.conf /etc/php7/php-fpm.d/
COPY ./nginx.conf /etc/nginx/
COPY ./wp-config.php /var/www/wordpress/
COPY ./create_authors.php /var/www/wordpress/wp-content/mu-plugins/
RUN chown -R www:www /var/www/
EXPOSE 5050
RUN rc default && rc-service nginx start && rc-service php-fpm7 start
RUN rc-service nginx stop && rc-service php-fpm7 stop
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
