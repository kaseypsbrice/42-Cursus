SCRIPT=./srcs/requirements/tools/setup.sh

all:
	@$(SCRIPT) && docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down -v

re:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

#clean:
#	@docker stop $$(docker ps -qa);\
#	docker rm $$(docker ps -qa);\
#	docker rmi -f $$(docker images -qa);\
#	docker volume rm $$(docker volume ls -q);\
#	docker network rm $$(docker network ls -q) 2>/dev/null;
# - Stops all running docker containers 
# - Removes all docker containers
# - Forcefully removes all docker images
# - Removes all docker volumes
# - Removes all docker networks
# The -q option stands for 'quiet'. This way, only the numeric IDs
# of docker objects will appear without any additional information.

.PHONY: all re down clean
