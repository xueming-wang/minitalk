# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 14:43:07 by xuwang            #+#    #+#              #
#    Updated: 2021/06/19 18:43:33 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= server
CFLAGS 	= -Wall -Wextra -Werror
CC 		= gcc
SRCS	= utils.c
SRCS_S 	= server.c
SRCS_C 	= client.c
OBJS	= utils.o
OBJS_S	= server.o
OBJS_C 	= client.o
CLIENT	= client

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_S) $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_S) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_C) -o $(CLIENT)

clean:
		rm -rf $(OBJS) $(OBJS_S) $(OBJS_C) 

fclean: clean
		rm -rf $(NAME) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
