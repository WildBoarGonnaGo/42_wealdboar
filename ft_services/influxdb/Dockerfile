# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 19:21:23 by lchantel          #+#    #+#              #
#    Updated: 2020/12/24 19:06:39 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk update && apk -U -a upgrade
RUN apk add influxdb telegraf
COPY ./telegraf.conf /etc/
COPY ./influxdb.conf /etc/
COPY ./launch.sh .
RUN chmod 755 ./launch.sh
EXPOSE 8086
CMD /launch.sh
