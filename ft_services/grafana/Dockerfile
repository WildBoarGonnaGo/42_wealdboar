# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/20 16:55:28 by lchantel          #+#    #+#              #
#    Updated: 2020/12/24 20:51:47 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk update && apk -U -a upgrade
RUN apk add grafana
COPY ./wildboar.dashboard.conf.yaml /usr/share/grafana/conf/provisioning/dashboards/
COPY ./wildboar.datasources.conf.yaml /usr/share/grafana/conf/provisioning/datasources/
COPY ./custom.ini /usr/share/grafana/conf/
EXPOSE 3000
CMD ["/usr/sbin/grafana-server", "--homepath=/usr/share/grafana"]
