CREATE DATABASE wordpress;
DELETE FROM mysql.user WHERE user = '';
GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%' IDENTIFIED BY 'admin';
SET PASSWORD FOR 'admin'@'%' = PASSWORD('admin');
FLUSH PRIVILEGES;
