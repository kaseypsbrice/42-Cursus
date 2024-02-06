# Base image / What our image will be built upon
FROM alpine:3.18

# Updates and installs necessary packages
RUN apk update && apk add --no-cache nginx openssl

# Creates directory to store certificates
RUN mkdir /etc/nginx/ssl

# Generates a new private key using OpenSSL and stores it
RUN openssl genpkey -algorithm RSA -out etc/ssl/private.key

# Generates a certificate by specifying the:
# - Type of certificate
# - Duration of its validity
# - Private key used for generating the certificate
# - Output file path
# - Subject information for the certificate
RUN openssl req -new -x509 -days 365 -key etc/ssl/private.key \
	-out etc/ssl/certificate.pem -subj \
	"/C=AU/ST=SA/L=Adelaide/O=42 Adelaide/CN=kbrice.42.fr"
# /C=AU			: Country (C)
# /ST=SA 		: State (ST)
# /L=Adelaide		: Locality/City (L)
# /O=42 Adelaide	: Organisation (O)
# /CN=kbrice.42.fr	: Common Name (CN) e.g. domain name

# Copy our custom configuration to nginx
COPY ./conf/nginx.conf /etc/nginx/conf.d
COPY tools/entrypoint.sh /

# Sets the entry point for the container
ENTRYPOINT ["/entrypoint.sh"]

# Indicates what port the container will be listening on
EXPOSE 443

# Tells nginx to run in the foreground and not as a daemon
# Prevents the container from terminating
# Common practice when running nginx within Docker containers
CMD ["nginx", "-g", "daemon off;"]
