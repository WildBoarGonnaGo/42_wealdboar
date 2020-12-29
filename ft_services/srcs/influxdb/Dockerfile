# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 19:21:23 by lchantel          #+#    #+#              #
#    Updated: 2020/12/29 21:46:31 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk update && apk -U -a upgrade
RUN apk add influxdb telegraf supervisor
COPY ./telegraf.conf /etc/
COPY ./influxdb.conf /etc/
COPY ./supervisord.conf /etc/supervisord.conf
EXPOSE 8086
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"] 
