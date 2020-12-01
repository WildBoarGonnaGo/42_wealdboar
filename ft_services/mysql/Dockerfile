# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 16:35:16 by lchantel          #+#    #+#              #
#    Updated: 2020/11/29 20:31:10 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk upgrade -a -U
RUN apk add mysql mysql-client openrc
RUN chown -R mysql:mysql /var/lib/mysql/
COPY ./my.cnf /etc/
COPY ./secure_config.sh /root
RUN /etc/init.d/mariadb setup
RUN /etc/init.d/mariadb start
RUN chmod 755 /root/secure_config.sh
RUN /root/secure_config.sh
RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf
RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf
RUN sed -i "s|.*skip-networking.*|skip-networking|g" /etc//my.cnf
RUN sed -i "s|.*skip-networking.*|skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
CMD rc default 
