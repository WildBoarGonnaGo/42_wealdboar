CREATE DATABASE wordpress;
DROP DATABASE test;
CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';
/*CREATE USER 'lchantel'@'%' IDENTIFIED BY 'lchantel';
CREATE USER 'pstein'@'%' IDENTIFIED BY 'pstein';
CREATE USER 'admins_mom'@'%' IDENTIFIED BY 'admins_mom';*/
DELETE FROM mysql.user WHERE user = '';
SET PASSWORD FOR 'admin'@'%' = PASSWORD('urdaddyduty');
/*SET PASSWORD FOR 'admins_mom'@'%' = PASSWORD('killadmin');
SET PASSWORD FOR 'pstein'@'%' = PASSWORD('yolomlg');
SET PASSWORD FOR 'lchantel'@'%' = PASSWORD('guy');*/
GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%' IDENTIFIED BY 'admin';
FLUSH PRIVILEGES;
