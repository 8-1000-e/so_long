# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 23:40:20 by edubois-          #+#    #+#              #
#    Updated: 2024/11/21 19:26:28 by edubois-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	so_long  

DIR_LIB 		:= 	lib
LIBFT_DIR 		:=	$(DIR_LIB)/libft
PRINTF_DIR 		:=	$(DIR_LIB)/printf
GNL_DIR 		:=	$(DIR_LIB)/gnl

LIBFT_LIB 		:= $(LIBFT_DIR)/libft.a
PRINTF_LIB 		:= $(PRINTF_DIR)/libftprintf.a
GNL_LIB 		:= $(GNL_DIR)/gnl.a

DIR_MLX     	:= $(DIR_LIB)/MacroLibX
MLX_INCLUDES    := $(DIR_MLX)/includes
MLX             := $(DIR_MLX)/libmlx.so

IFLAGS          := -I $(MLX_INCLUDES)/

SRCS = main.c											\
	srcs/parse_map_check_data/parse_map.c				\
	srcs/get_map/get_map.c								\
	srcs/get_data/get_data.c							\
	srcs/parse_map_check_data/check_map.c				\
	srcs/parse_map_check_data/flood_fill.c				\
	srcs/parse_map_check_data/parse_getmap_utils.c		\
	srcs/game/launch_game.c								\
	srcs/get_data/fill_data_game.c						\
	srcs/game/destroy_graphic.c							\
	srcs/game/graphic/put_image.c						\
	srcs/game/check_action.c							\
	srcs/game/manage_hook.c								\
	srcs/game/make_mouvement.c							\
	srcs/game/print_moov.c								\
	srcs/game/manage_rhino.c							\
	srcs/game/manage_sprite.c							\

OBJS 			:= $(SRCS:.c=.o)

CC 				:= @cc
FLAGS 			:= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):	$(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(OBJS)
	make -s -C $(DIR_MLX) -j16
	$(CC) $(FLAGS) $(IFLAGS) -o $(NAME) -lm -lSDL2 $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(MLX)
	@echo $(ART)

$(MLX):
	-s -C $(DIR_MLX) --no-print-directory -j

$(LIBFT_LIB):
	make -s -C  $(LIBFT_DIR)

$(PRINTF_LIB):
	make -s -C  $(PRINTF_DIR)

$(GNL_LIB):
	make -s -C  $(GNL_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -s -C  $(LIBFT_DIR)
	make clean -s -C  $(PRINTF_DIR)
	make clean -s -C  $(GNL_DIR)
	make clean -s -C  $(DIR_MLX)
	rm -f $(OBJS)

fclean: clean
	make fclean -s -C  $(LIBFT_DIR)
	make fclean -s -C  $(PRINTF_DIR)
	make fclean -s -C  $(GNL_DIR)
	make fclean -s -C  $(DIR_MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:

ART	:= "                                     ░▒▓███████▓▒░░▒▓██████▓▒░░             ▒▓█▓▒░      ░▒▓██████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░                                                                                   ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                                                                  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                                                                                          ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░                                                                                         ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                                                                         ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                                                                  ░▒▓███████▓▒░ ░▒▓██████▓▒░▒ ▓████████▓▒ ▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░                                                                                                                                 ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                         ██  ██                                                                                                                                                                     ██▒▒  ▒▒██                                                                                                                                                                 ██▒▒▒▒  ▒▒▒▒██                                                                                                                                                             ██▒▒▒▒▒▒  ▒▒▒▒▒▒██                                                                                                                                                       ████▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒████                                                                                                                                                 ██▓▓▒▒▒▒▒▒████  ████▒▒▒▒▒▒▓▓██                                                                                                                                             ██▓▓▓▓▒▒▒▒██▓▓▒▒  ▒▒▓▓██▒▒▓▓▓▓▒▒██                                                                                                                                         ██▓▓▓▓▓▓▓▓██████      ██████▓▓▓▓▓▓▓▓██                                                                                                                                       ██▓▓▓▓▓▓██▒▒▒▒▒▒██  ██▒▒▒▒▒▒██▓▓▓▓▓▓██                                                                                                                                         ██████▒▒▒▒▒▒▒▒██▒▒██▒▒▒▒▒▒▒▒██████                                                                                                                                               ██▒▒▒▒▒▒██▒▒▒▒▒▒██▓▓▒▒▒▒██                                                                                                                                                 ██▒▒▒▒▓▓██▓▓▒▒▒▒▒▒▒▒██▒▒▒▒▒▒██                                                                                                                                               ██▒▒▒▒██▓▓▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒██                                                                                                                                                 ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                     ████▒▒▒▒██████▒▒▒▒████                                                                                                                                                           ████▒▒▒▒▒▒████                                                                                                                                                             ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                         ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                     ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                   ██▒▒▒▒████▒▒▒▒▒▒████▒▒▒▒██                                                                                                                                                   ██▒▒██    ██▒▒██    ██▒▒██                                                                                                                                                   ██▒▒██  ██▒▒▒▒▒▒██  ██▒▒██                                                                                                                                                   ██▒▒████▒▒▒▒▒▒▒▒▒▒████▒▒██                                                                                                                                                   ██▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒██                                                                                                                                                   ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                   ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                     ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                         ████▒▒▒▒▒▒▒▒▒▒████                                                                                                                                                               ██████████                                                                                "
