# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 23:40:20 by edubois-          #+#    #+#              #
#    Updated: 2024/11/07 18:49:39 by edubois-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = SRCS/libft
PRINTF_DIR = SRCS/printf
GNL_DIR = SRCS/gnl

LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
GNL_LIB = $(GNL_DIR)/gnl.a

SRCS = main.c\
	parse_map.c\
	get_map.c\
	get_data.c\
	check_map.c\
	flood_fill.c\
	parse_getmap_utils.c\

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g

all: $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)
	rm -f

re: fclean all

.PHONY: all clean fclean re