/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:13:28 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/12 13:14:59 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "SRCS/libft/libft.h"
# include "SRCS/printf/ft_printf.h"
# include "SRCS/gnl/get_next_line.h"
# include <fcntl.h>
#include "SRCS/MacroLibX/includes/mlx.h"

typedef struct s_start
{
	int	x;
	int	y;
}	t_start;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_stack
{
	int	x;
	int	y;
}	t_stack;

typedef struct s_data
{
	int			nb_items;
	t_player	player;
	t_start		s;
	char		**map;
	int			max_x;
	int			max_y;
}	t_data;

int		check_data(t_data *data);
int		find_exit(t_data *data);
int		check_format(char **tab);
int		find_start(t_data *data);
void	getdata(t_data *data, char **tab);
int		nb_items(t_data *data);
char	**get_map(int fd);
void	*free_lst(t_list *lst);
int		nb_line_fd(int fd, t_list *lst);
int		main(int ac, char **av);
int		free_map(char **map);
int		get_parsed_map(char **tab, t_data *data);
int		nb_line(char **tab);
int		tab_len(char **tab);
int		get_x_start(char **tab);
int		get_y_start(char **tab);
int		send_error_message(t_data *data);
int		flood_fill(t_data *data);
void    start_game(t_data *data);

#endif