# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 19:15:48 by lchantel          #+#    #+#              #
#    Updated: 2020/12/14 20:30:02 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
RUN apk update && apk -U -a upgrade
RUN apk add vsftpd supervisor openrc openssl
EXPOSE 21
CMD /bin/sh
