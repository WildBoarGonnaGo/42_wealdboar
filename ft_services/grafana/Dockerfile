# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/20 16:55:28 by lchantel          #+#    #+#              #
#    Updated: 2020/12/20 17:33:14 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -U -a upgrade
RUN apk add fontconfig 
RUN wget https://dl.grafana.com/enterprise/release/grafana-enterprise_7.3.6_amd64.deb

EXPOSE 3000
CMD sh
