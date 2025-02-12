# Main
CLIENT_NAME				=	client
SERVER_NAME				=	server
CC					=	gcc

CFLAGS				=	-Wall -Werror -Wextra -Idependencies/ft_libc/includes -Iincludes -fPIE
RM					=	rm -rf
MAKE				=	make --no-print-directory -C

# Colors
RESET				=	\033[0m
BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[1;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[1;35m
CYAN				=	\033[1;36m
WHITE				=	\033[0;37m

# Symbols
OK					=	✓
FAIL				=	✗
INFO				=	ⓘ

# Sources and Objects
FT_LIBC 			= ./dependencies/ft_libc/ft_libc.a

SRCS				=	src/server.c\
						src/client.c

SERVER_SRCS			=	src/server.c
CLIENT_SRCS			=	src/client.c

SRC_COUNT			=	$(words $(SRCS))

SERVER_OBJS			=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SERVER_SRCS))
CLIENT_OBJS			=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(CLIENT_SRCS))

OBJ_DIR				=	objects

ifeq ($(GOOD_LOOKING_MESSAGES), 1)
	CFLAGS += -DGOOD_LOOKING_MESSAGES=1
endif

all : client server

client : header $(FT_LIBC) $(CLIENT_OBJS)
		@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_LIBC) -o $(CLIENT_NAME)


server : header $(FT_LIBC) $(SERVER_OBJS)
		@if [ ! -e "$(SERVER_NAME)" ]; then \
			printf "]\n" ; \
		fi
		@$(CC) $(CFLAGS) $(SERVER_OBJS) $(FT_LIBC) -o $(SERVER_NAME)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "$(GREEN)$(OK)$(RESET)"

$(OBJ_DIR): $(OBJS)
		@if [ ! -d "$(OBJ_DIR)" ]; \
			then mkdir -p "$(OBJ_DIR)"; \
		fi

$(FT_LIBC) :
	@if [ ! -e "$(shell dirname $@)" ]; then \
		git clone git@github.com:R0-main/ft_libc.git $(shell dirname $@); \
	fi;
	@$(MAKE) $(shell dirname $@) SAFE=1

header:
		@echo "\
			   _____  .__       ._____________      .__   __ \n\
			  /     \ |__| ____ |__\__    ___/____  |  | |  | __ \n\
			 /  \ /  \|  |/    \|  | |    |  \__  \ |  | |  |/ / \n\
			/    Y    \  |   |  \  | |    |   / __ \|  |_|    < \n\
			\____|__  /__|___|  /__| |____|  (____  /____/__|_ \ \n\
			        \/        \/                  \/          \/ \n\
		";
		@printf  "\n";
		@if [ ! -e "$(CLIENT_NAME)" -a ! -e "$(CLIENT_NAME)" ]; \
			then printf "Compiling Project : ["; \
		fi

clean :
		@$(RM) $(OBJ_DIR)
		@$(MAKE) $(shell dirname $(FT_LIBC)) fclean

fclean : clean
		@$(RM) $(CLIENT_NAME)
		@$(RM) $(SERVER_NAME)

re : fclean all

.PHONY: all clean fclean re header
