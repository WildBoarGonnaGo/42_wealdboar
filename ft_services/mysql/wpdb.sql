-- Set up new database for wordpress
CREATE DATABASE wordpress;
CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';
CREATE USER 'lchantel'@'localhost' IDENTIFIED BY 'lchantel';
SET PASSWORD FOR 'admin'@'localhost' = PASSWORD("urmom");
GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'localhost' IDENTIFIED BY 'admin';

