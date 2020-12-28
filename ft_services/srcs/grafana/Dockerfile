# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/20 16:55:28 by lchantel          #+#    #+#              #
#    Updated: 2020/12/28 00:40:48 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk update && apk -U -a upgrade
RUN apk add grafana
COPY ./dashboard.conf.yaml /usr/share/grafana/conf/provisioning/dashboards/dashboards.yaml
COPY ./datasources.conf.yaml /usr/share/grafana/conf/provisioning/datasources/datasources.yaml
COPY ./custom.ini /usr/share/grafana/conf/
COPY ./dashboard/* /usr/share/grafana/public/dashboards/
RUN rm -f  /usr/share/grafana/conf/provisioning/dashboards/sample.yaml
RUN rm -f  /usr/share/grafana/conf/provisioning/datasources/sample.yaml
VOLUME /usr/share/grafana/
EXPOSE 3000
CMD ["/usr/sbin/grafana-server", "--homepath=/usr/share/grafana"]
