FROM alpine:latest
RUN apk update && apk -a -U upgrade
RUN apk add nginx openssh openrc openssl
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx/
RUN chown -R www:www /www
RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 -subj \
"/C=RU/ST=Moscow/L=Moscow/O=lchantel/CN=localhost" -keyout \
/etc/ssl/private/lchantel.key -out /etc/ssl/certs/lchantel.crt
RUN cp /var/lib/nginx/html/index.html /www/
RUN cp /etc/nginx/nginx.conf /root
COPY ./default.conf /etc/nginx/conf.d/
EXPOSE 80 443
RUN rc-update add nginx default
CMD rc default && rc-service nginx start && bin/sh
