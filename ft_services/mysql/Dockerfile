# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 16:35:16 by lchantel          #+#    #+#              #
#    Updated: 2020/12/19 00:03:15 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk upgrade -a -U
RUN apk add mysql mysql-client openrc supervisor
COPY ./mariadb-server.cnf /etc/my.cnf
RUN chmod 755 /etc/my.cnf 
#COPY ./secure_config.sh /root
# RUN rc default
# RUN /etc/init.d/mariadb setup
# RUN /etc/init.d/mariadb start
#RUN chmod 755 /root/secure_config.sh
#RUN /root/secure_config.sh
# RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf
# RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf
# RUN sed -i "s|.*skip-networking.*|skip-networking|g" /etc/my.cnf
# RUN sed -i "s|.*skip-networking.*|skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
RUN mkdir /sql_data
COPY ./wpdb.sql /sql_data
COPY ./launch.sh /
RUN chmod 755 ./launch.sh
RUN chown -R mysql:mysql /sql_data
#RUN  mysql_install_db --skip-test-db --user=mysql --datadir=/var/lib/mysql
VOLUME /var/lib/mysql/
# RUN chown -R mysql:root /var/lib/mysql/
#RUN  mysql_install_db --skip-test-db --user=mysql --datadir=/var/lib/mysql
RUN mkdir -p /run/mysqld/
EXPOSE 3306
CMD /launch.sh 
#./launch.sh
#mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/sql_data/wpdb.sql

