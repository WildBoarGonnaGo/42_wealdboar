# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    indx_disable.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 18:07:57 by lchantel          #+#    #+#              #
#    Updated: 2020/10/30 18:08:02 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/bash

cp /var/www/html/autoindex_state/lchntl_indx_off /etc/nginx/sites-available/default
service nginx restart
