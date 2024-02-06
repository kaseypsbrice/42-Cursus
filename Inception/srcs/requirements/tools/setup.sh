#!/bin/bash

if [ ! -d /home/kbrice/data ]; then
	mkdir /home/kbrice/data/mariadb_data
	mkdir /home/kbrice/data/wordpress_data
fi

# If you don't include this file, we won't have anywhere to
# mount the volumes for mariadb and wordpress (:
