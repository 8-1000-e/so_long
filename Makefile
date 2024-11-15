# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 23:40:20 by edubois-          #+#    #+#              #
#    Updated: 2024/11/15 02:17:00 by edubois-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR =LIB/libft
PRINTF_DIR = LIB/printf
GNL_DIR = LIB/gnl
DIR_LIB = LIB

LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
GNL_LIB = $(GNL_DIR)/gnl.a

DIR_MLX         := $(DIR_LIB)/MacroLibX
MLX_INCLUDES    := $(DIR_MLX)/includes
MLX                := $(DIR_MLX)/libmlx.so

IFLAGS            := -I $(MLX_INCLUDES)/

SRCS = main.c\
	parse_map_check_data/parse_map.c\
	get_map/get_map.c\
	get_data/get_data.c\
	parse_map_check_data/check_map.c\
	parse_map_check_data/flood_fill.c\
	parse_map_check_data/parse_getmap_utils.c\
	game/launch_game.c\
	get_data/fill_data_game.c\
	game/destroy_graphic.c\
	game/graphic/put_image.c\
	game/check_action.c\
	game/manage_hook.c\
	

OBJS = $(SRCS:.c=.o)

CC = @cc
FLAGS = -Wall -Wextra -Werror -g

all: $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(OBJS)
	$(CC) $(FLAGS) $(IFLAGS) -lm -lSDL2 $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(MLX)
	@echo "                                         ░▒▓███████▓▒░░▒▓██████▓▒░░             ▒▓█▓▒░      ░▒▓██████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░                                          "
	@echo "                                        ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                         "
	@echo "                                        ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                                                "
	@echo "                                         ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░                                         "
	@echo "                                               ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                         "
	@echo "                                               ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                         "
	@echo "                                        ░▒▓███████▓▒░ ░▒▓██████▓▒░▒ ▓████████▓▒ ▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░                                          "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                      ██                                                                                    "
	@echo "                                                                                    ██  ██                                                                                  "
	@echo "                                                                                  ██▒▒  ▒▒██                                                                                "
	@echo "                                                                                ██▒▒▒▒  ▒▒▒▒██                                                                              "
	@echo "                                                                              ██▒▒▒▒▒▒  ▒▒▒▒▒▒██                                                                            "
	@echo "                                                                          ████▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒████                                                                        "
	@echo "                                                                        ██▓▓▒▒▒▒▒▒████  ████▒▒▒▒▒▒▓▓██                                                                      "
	@echo "                                                                      ██▓▓▓▓▒▒▒▒██▓▓▒▒  ▒▒▓▓██▒▒▓▓▓▓▒▒██                                                                    "
	@echo "                                                                    ██▓▓▓▓▓▓▓▓██████      ██████▓▓▓▓▓▓▓▓██                                                                  "
	@echo "                                                                    ██▓▓▓▓▓▓██▒▒▒▒▒▒██  ██▒▒▒▒▒▒██▓▓▓▓▓▓██                                                                  "
	@echo "                                                                      ██████▒▒▒▒▒▒▒▒██▒▒██▒▒▒▒▒▒▒▒██████                                                                    "
	@echo "                                                                          ██▒▒▒▒▒▒██▒▒▒▒▒▒██▓▓▒▒▒▒██                                                                        "
	@echo "                                                                        ██▒▒▒▒▓▓██▓▓▒▒▒▒▒▒▒▒██▒▒▒▒▒▒██                                                                      "
	@echo "                                                                        ██▒▒▒▒██▓▓▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒██                                                                      "
	@echo "                                                                          ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                        "
	@echo "                                                                            ████▒▒▒▒██████▒▒▒▒████                                                                          "
	@echo "                                                                                ████▒▒▒▒▒▒████                                                                              "
	@echo "                                                                              ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                            "
	@echo "                                                                            ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                          "
	@echo "                                                                          ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                        "
	@echo "                                                                          ██▒▒▒▒████▒▒▒▒▒▒████▒▒▒▒██                                                                       "
	@echo "                                                                          ██▒▒██    ██▒▒██    ██▒▒██                                                                        "
	@echo "                                                                          ██▒▒██  ██▒▒▒▒▒▒██  ██▒▒██                                                                        "
	@echo "                                                                          ██▒▒████▒▒▒▒▒▒▒▒▒▒████▒▒██                                                                        "
	@echo "                                                                          ██▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒██                                                                        "
	@echo "                                                                          ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                        "
	@echo "                                                                          ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                        "
	@echo "                                                                            ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                          "
	@echo "                                                                              ████▒▒▒▒▒▒▒▒▒▒████                                                                            "
	@echo "                                                                                  ██████████                                                                                "

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
	rm -f $(OBJS)

fclean: clean
	make fclean -s -C  $(LIBFT_DIR)
	make fclean -s -C  $(PRINTF_DIR)
	make fclean -s -C  $(GNL_DIR)
	rm -f

re: fclean all

.PHONY: all clean fclean re
.SILENT: