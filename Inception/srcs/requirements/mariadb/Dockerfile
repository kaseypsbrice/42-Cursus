FROM alpine:3.18

RUN apk update && apk add --no-cache \
	mariadb mariadb-client

# Copy the scripts and configuration files
COPY ./tools/createdb.sh /createdb.sh
COPY ./tools/init.sql /mariadb-conf.d/init.sql
COPY ./conf/my.cnf /etc/mysql/my.cnf
# Make the script executable
RUN chmod +x /createdb.sh

# Expose port 3306
EXPOSE 3306

# Runs the script when the container starts up
CMD ["./createdb.sh"]
