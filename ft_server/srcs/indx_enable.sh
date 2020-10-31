# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    indx_enable.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 18:06:44 by lchantel          #+#    #+#              #
#    Updated: 2020/10/30 18:06:52 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/bash

cp /var/www/html/autoindex_state/lchntl_indx_on /etc/nginx/sites-available/default
service nginx restart
