# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    nginx_conf.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 23:37:24 by lchantel          #+#    #+#              #
#    Updated: 2020/12/03 17:49:14 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/sh

cp /var/lib/nginx/html/index.html /www/
rc default
rc-service sshd start
ssh-keygen -A
rc-service sshd stop
/usr/bin/supervisord -c /etc/supervisord.conf
