#!bin/sh

rc default
chmod 777 /wpdb.sh && /wpdb.sh
rc-service mariadb stop
/usr/bin/supervisord -c /etc/supervisord.conf
