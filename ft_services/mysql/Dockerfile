# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 16:35:16 by lchantel          #+#    #+#              #
#    Updated: 2020/12/17 01:37:21 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk upgrade -a -U
RUN apk add mysql mysql-client openrc supervisor
COPY ./my.cnf /etc/
COPY ./secure_config.sh /root
RUN rc default
RUN /etc/init.d/mariadb setup
RUN /etc/init.d/mariadb start
RUN chmod 755 /root/secure_config.sh
RUN /root/secure_config.sh
RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf
RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf
RUN sed -i "s|.*skip-networking.*|skip-networking|g" /etc/my.cnf
RUN sed -i "s|.*skip-networking.*|skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
RUN mkdir /sql_data
COPY ./wpdb.sql ./sql_data
# COPY ./sql_launch.sh .
# RUN chmod 755 /wpdb.sh
RUN chown -R mysql:mysql /sql_data
#RUN chmod 755 /sql_launch.sh
#COPY ./supervisord.conf /etc/
RUN  mysql_install_db --skip-test-db --user=mysql --datadir=/var/lib/mysql
EXPOSE 3306
CMD mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/sql_data/wpdb.sql

