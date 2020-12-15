#!bin/sh

rc default
chmod 755 /wpdb.sh
/wpdb.sh
rc-service mariadb stop
/usr/bin/supervisord -c /etc/supervisord.conf
rc-service mariadb start
