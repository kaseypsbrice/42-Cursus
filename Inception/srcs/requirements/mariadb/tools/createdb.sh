#!/bin/bash

# Replaces the placeholders in init.sql with the value of the 
# environment variables.
sed -i "s/\:DB_NAME/${MYSQL_DATABASE}/g" /mariadb-conf.d/init.sql
sed -i "s/\:USER/${MYSQL_USER}/g" /mariadb-conf.d/init.sql
sed -i "s/\:UPASS/${MYSQL_PASSWORD}/g" /mariadb-conf.d/init.sql
sed -i "s/\:ADMIN/${MYSQL_ROOT}/g" /mariadb-conf.d/init.sql
sed -i "s/\:APASS/${MYSQL_ROOT_PASSWORD}/g" /mariadb-conf.d/init.sql

# Creates directories for mariadb to store it's runtime files in.
# These files will contain things like the PID of the current
# running instance.
if [ ! -d /var/run/mysqld ]; then
 mkdir /var/run/mysqld
fi
if [ ! -d /run/mysqld ]; then
 mkdir /run/mysqld
fi

# Checks whether the MySQL/MariaDB directory has been initialised.
# Initialises the directory if it hasn't been already.
if [ ! -d /var/lib/mysql/mysql ]; then
 mysql_install_db --user=root
fi

# Starts mariaDB in the background
service mariadb start

# Checks whether the server is up or not by sending a ping to the
# server continuously until it responds.
while ! mysqladmin ping -hlocalhost --silent 2>/dev/null; do
 sleep 1
done

# Connects to the mariaDB server as root, then executes the commands
# in the init.sql file.
mysql -u root < /mariadb-conf.d/init.sql

# Stops the MariaDB service
service mariadb stop
while  mysqladmin ping -hlocalhost --silent 2>/dev/null; do
 sleep 1
done

# Runs the mariaDB service in the foreground
exec mysqld -u root
