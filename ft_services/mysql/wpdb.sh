#!/bin/sh

mysql -e "CREATE DATABASE wordpress;"
mysql -e "DROP DATABASE test;"
mysql -e "USE wordpress;"
mysql -e "CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';"
mysql -e "CREATE USER 'lchantel'@'%' IDENTIFIED BY 'lchantel';"
mysql -e "CREATE USER 'pstein'@'%' IDENTIFIED BY 'pstein'"
mysql -e "CREATE USER 'admins_mom'@'%' IDENTIFIED BY 'admins_mom'"
mysql -e "DELETE FROM mysql.user WHERE user = '';"
mysql -e "SET PASSWORD FOR 'admins_mom'@'%' = PASSWORD('killadmin');"
mysql -e "SET PASSWORD FOR 'admin'@'%' = PASSWORD('urdaddyduty');"
mysql -e "SET PASSWORD FOR 'pstein'@'%' = PASSWORD('yolomlg');"
mysql -e "SET PASSWORD FOR 'lchantel'@'%' = PASSWORD('guy');"
mysql -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%' IDENTIFIED BY 'admin';"
mysql -e "FLUSH PRIVILEGES;"
