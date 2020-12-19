#!/bin/sh

mysql_install_db --skip-test-db --user=mysql --datadir=/var/lib/mysql
mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/sql_data/wpdb.sql
