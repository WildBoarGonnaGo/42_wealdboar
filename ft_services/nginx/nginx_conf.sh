# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    nginx_conf.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 23:37:24 by lchantel          #+#    #+#              #
#    Updated: 2020/11/27 00:59:03 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cp /var/lib/nginx/html/index.html /www/
nginx -g "daemon off;"
