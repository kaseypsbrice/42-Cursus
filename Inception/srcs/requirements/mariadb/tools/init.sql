-- Creates database needed by wordpress
create database if not exists :DB_NAME;

-- Creates the user that wordpress will use to connect to the database
-- The '%' wildcard allows the user to connect from any host, 
-- which means the user doesn't necessarily have to be on the same machine
-- or container in order to connect.
create user if not exists ':USER'@'%' identified by ':UPASS';

-- Gives the user the necessary privileges to perform CRUD operations
-- CRUD (Create, Read, Update, Delete).
grant all privileges on :DB_NAME.* to ':USER'@'%' identified by ':UPASS';

-- Reloads privileges so that any changes take effect immediately
flush privileges;

-- Creates our admin user
create user if not exists ':ADMIN'@'%' identified by ':APASS';

-- Grants all possible privileges to the Admin
grant all privileges on *.* to ':ADMIN'@'%';

-- Reload once more to update the Admin's privileges
flush privileges;
