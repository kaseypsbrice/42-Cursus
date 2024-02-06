FROM alpine:3.18

RUN apk update && apk add --no-cache \
curl \
mariadb-client \
php81 \
php81-common php81-fpm php81-mysqli php81-mysqlnd \
php81-openssl

COPY conf/www.conf /etc/php8.1/php-fpm.d/www.conf
COPY tools/create-site.sh /create-site.sh

RUN chmod +x /create-site.sh

CMD ["bash", "./create-ste.sh"]
