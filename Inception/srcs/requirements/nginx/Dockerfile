# Base image / What our image will be built upon
FROM alpine:3.18

# Updates and installs necessary packages
RUN apk update && apk add --no-cache nginx openssl

# Creates directory to store certificates
RUN mkdir /etc/nginx/ssl

# Generates a certificate by specifying the:
# - Type of certificate
# - Duration of its validity
# - Private key used for generating the certificate
# - Output file path
# - Subject information for the certificate
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/ssl/certificate.pem \
	-keyout /etc/ssl/private.key \
	-subj "/C=AU/ST=SA/L=Adelaide/O=42 Adelaide/CN=kbrice.42.fr"
# /C=AU			: Country (C)
# /ST=SA 		: State (ST)
# /L=Adelaide		: Locality/City (L)
# /O=42 Adelaide	: Organisation (O)
# /CN=kbrice.42.fr	: Common Name (CN) e.g. domain name

#RUN chmod +w /etc/nginx/conf.d/default.conf
RUN rm -f /etc/nginx/conf.d/default.conf

# Copy our custom configuration to nginx
COPY ./conf/nginx.conf /etc/nginx/conf.d/default.conf
COPY tools/entrypoint.sh /

RUN chmod +x /entrypoint.sh

# Sets the entry point for the container
ENTRYPOINT ["/entrypoint.sh"]

# Indicates what port the container will be listening on
EXPOSE 443

# Tells nginx to run in the foreground and not as a daemon
# Prevents the container from terminating
# Common practice when running nginx within Docker containers
CMD ["nginx", "-g", "daemon off;"]
