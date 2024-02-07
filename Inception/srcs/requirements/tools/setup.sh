#!/bin/bash

if [ ! -d /home/kbrice/data ]; then
	mkdir /home/kbrice/data/mariadb_data
	mkdir /home/kbrice/data/wordpress_data
fi

# if [ -f "/etc/nginx/conf.d/default.conf" ]; then
#     sudo chmod +w /etc/nginx/conf.d/default.conf
#     sudo rm -f /etc/nginx/conf.d/default.conf
# fi
