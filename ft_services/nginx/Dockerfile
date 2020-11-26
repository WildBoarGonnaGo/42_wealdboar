# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 16:16:21 by lchantel          #+#    #+#              #
#    Updated: 2020/11/26 21:51:19 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk upgrade -U -a
RUN apk add nginx
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www/
RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 -subj \
"/C=RU/ST=Moscow/L=Moscow/O=lchantel/CN=localhost" -keyout \
/etc/ssl/private/lchantel.key -out /etc/ssl/certs/lchantel.crt
COPY 
#CMD ["/bin/sh", "script.sh"]
