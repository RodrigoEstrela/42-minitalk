# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 14:10:19 by rdas-nev          #+#    #+#              #
#    Updated: 2022/04/05 16:08:08 by rdas-nev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS		=	server.c ft_recursive_power.c libftprintf.a \

CLIENT_SRCS		=	client.c ft_atoi.c ft_isprint.c libftprintf.a \

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SERVER		= server

CLIENT		= client

# === Colors ===
RED			= \e[1;3;31m
GREEN		= \e[1;3;32m
CYAN		= \e[1;3;36m
RESET		= \e[0m

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_SRCS)
			@$(CC) -o $(SERVER) $(SERVER_SRCS)
			@printf "$(GREEN)Successfully Built Server 🥅$(RESET)\n"

$(CLIENT):	$(CLIENT_SRCS)
			@$(CC) -o $(CLIENT) $(CLIENT_SRCS)
			@printf "$(CYAN)Successfully Built Client ⚽️$(RESET)\n"

clean:
			@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT)
			@printf "$(RED)Successfully Removed Files 📉💥$(RESET)\n"

re:			fclean $(SERVER) $(CLIENT)	
