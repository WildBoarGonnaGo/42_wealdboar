# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 16:16:21 by lchantel          #+#    #+#              #
#    Updated: 2020/12/10 04:27:16 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk upgrade -U -a
RUN apk add nginx openssl openrc openssh supervisor openssl
RUN adduser -D -g 'www' www
RUN chown -R www:www /var/www/
RUN chown -R www:www /var/lib/nginx/
RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 -subj \
"/C=RU/ST=Moscow/L=Moscow/O=lchantel/CN=localhost" -keyout \
/etc/ssl/private/lchantel.key -out /etc/ssl/certs/lchantel.crt
COPY ./default.conf /etc/nginx/conf.d/default.conf
COPY ./supervisor.conf /etc/supervisord.conf
RUN mkdir -p /run/nginx/
EXPOSE 80 443 22
RUN rc-update add nginx default
RUN /usr/bin/ssh-keygen -A
RUN cp /var/lib/nginx/html/index.html /var/www/
RUN rc default
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
# CMD /bin/sh
