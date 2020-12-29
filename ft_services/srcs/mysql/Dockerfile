# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 16:35:16 by lchantel          #+#    #+#              #
#    Updated: 2020/12/29 20:21:33 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk upgrade -a -U
RUN apk add mysql mysql-client openrc supervisor
COPY ./mariadb-server.cnf /etc/my.cnf
RUN chmod 755 /etc/my.cnf 
RUN mkdir /sql_data
COPY ./wpdb.sql /sql_data
COPY ./launch.sh /
RUN chmod 755 ./launch.sh
RUN chown -R mysql:mysql /sql_data
VOLUME /var/lib/mysql/
RUN mkdir -p /run/mysqld/
EXPOSE 3306
CMD /launch.sh 
