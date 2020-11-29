# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    secure_config.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 15:06:26 by lchantel          #+#    #+#              #
#    Updated: 2020/11/29 18:50:15 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/sh
# Reset default root passord to new
mysql -e "SET PASSWORD FOR 'root'@localhost = PASSWORD("qwerty");"
# Remove all anonymous users
mysql -e "DROP USER ''@$(hostname);"
# Unabling remote root login
mysql -e "DELETE FROM mysql.user WHERE User-'root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');"
# Removing test database
mysql -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';"
# Commit our changes
mysql -e "FLUSH PRIVILEGES;"
# Rebooting mariadb service to make commit work
rc-service mariadb restart
# To make it work no matter what, we need to make systemboot
# And so, we just lets set mariadb to default runlevel like this
rc-update add mariadb default
