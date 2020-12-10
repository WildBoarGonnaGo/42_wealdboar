#!/bin/sh

mysql -e "CREATE DATABASE wordpress;"
mysql -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql -e "CREATE USER 'lchantel'@'localhost' IDENTIFIED BY 'lchantel';"
mysql -e "CREATE USER 'pstein'@'localhost' IDENTIFIED BY 'pstein'"
mysql -e "CREATE USER 'admins_mom'@'localhost' IDENTIFIED BY 'admins_mom'"
mysql -e "DELETE FROM mysql.user WHERE user = '';"
mysql -e "SET PASSWORD FOR 'admins_mom'@'localhost' = PASSWORD('killadmin');"
mysql -e "SET PASSWORD FOR 'admin'@'localhost' = PASSWORD('urdaddyduty');"
mysql -e "SET PASSWORD FOR 'pstein'@'localhost' = PASSWORD('yolomlg');"
mysql -e "SET PASSWORD FOR 'lchantel'@'localhost' = PASSWORD('guy');"
mysql -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql -e "FLUSH PRIVILEGES;"
