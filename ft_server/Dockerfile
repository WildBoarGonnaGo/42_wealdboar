# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 18:09:21 by lchantel          #+#    #+#              #
#    Updated: 2020/10/30 18:12:48 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get install -y nginx mariadb-server php7.3 \ 
php7.3-common php7.3-xmlrpc php7.3-soap php7.3-intl php7.3-cli php7.3-curl \
php7.3-fpm php7.3-mysql php7.3-mbstring php7.3-zip php7.3-gd php7.3-xml php-pear \
php7.3-gettext php7.3-cgi curl wget
#giving ownership to the 'www-data' user and group of /var/www/ directory
RUN chown -R www-data:www-data /var/www/
#creating script directory
#ssl-key for nginx
RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 -subj \
"/C=RU/ST=Moscow/L=Moscow/O=lchantel/CN=localhost" -keyout \
/etc/ssl/private/lchantel.key -out /etc/ssl/certs/lchantel.crt
#nginx configuration
RUN mkdir /var/www/html/autoindex_state/
COPY ./srcs/lchntl_indx_on /etc/nginx/sites-available/default
COPY ./srcs/lchntl_indx_on /var/www/html/autoindex_state
COPY ./srcs/lchntl_indx_off /var/www/html/autoindex_state
COPY ./srcs/indx_enable.sh .
COPY ./srcs/indx_disable.sh .
#install phpMyAdmin
#create phpMyAdmin install directory
RUN mkdir /var/www/html/phpmyadmin
#download 
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz -O phpmyadmin.tar.gz
RUN tar xzf phpmyadmin.tar.gz
RUN mv /phpMyAdmin-5.0.4-english/* ./var/www/html/phpmyadmin/
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin/
#install wordpress
#create mariadb database
RUN service mysql start && mysql --execute="CREATE DATABASE lchantel_db; CREATE USER 'lchantel'@'localhost' IDENTIFIED BY 'lchantel'; GRANT ALL PRIVILEGES ON lchantel_db.* TO 'lchantel'@'localhost'; FLUSH PRIVILEGES;"
#create wordpress root directory
#RUN mkdir /var/www/html/wordpress
RUN curl https:/wordpress.org/latest.tar.gz -o wordpress.tar.gz
RUN tar -xzf wordpress.tar.gz -C /var/www/html/
COPY ./srcs/wp-config.php /var/www/html/wordpress
#ports expose
EXPOSE 80 443
#run executable main script
COPY ./srcs/run.sh .
CMD bash run.sh
#CMD /bin/bash
