#!/bin/sh

set -eu

# Replaces the default domain name with our custom name
envsubst '${DOMAIN_NAME}' </etc/nginx/conf.d/nginx.conf>/etc/nginx/conf.d/www.conf

# If the private.key doesn't exist, generate one.
if [ ! -f "/etc/ssl/private.key" ]; then
	openssl genrsa -out "/etc/ssl/private.key" 4096
	openssl req -x509 -nodes -days 3655 \
		-key "/etc/ssl/private.key" \
		-out "/etc/ssl/certificate.pem" \
		-subj "/C=AU/ST=SA/L=Adelaide/O=42 Adelaide/CN=kbrice.42.fr"
fi

exec "$@"

