/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:13:28 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/15 01:27:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "LIB/libft/libft.h"
# include "LIB/printf/ft_printf.h"
# include "LIB/gnl/get_next_line.h"
# include <fcntl.h>
#include "LIB/MacroLibX/includes/mlx.h"
#include "SDL2/SDL_scancode.h"

typedef struct s_start
{
	int	x;
	int	y;
}	t_start;

typedef struct s_end
{
	int	x;
	int	y;
}	t_end;

typedef struct s_player
{
	int	x;
	int	y;
	void *sprite[12];
}	t_player;

typedef struct s_stack
{
	int	x;
	int	y;
}	t_stack;

typedef struct s_data
{
	int			nb_items;
	t_end		e;
	t_player	p;
	t_start		s;
	char		**map;
	int			max_x;
	int			max_y;
	int			items_picked;
	void *mlx;
	void *win;
	void *background;
	void *walls;
	void *items;
	void *player;
	void *exit;
	char pressed[SDL_NUM_SCANCODES];
	int			nb_moove;
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
int		get_x_items(char **tab, char c);
int		get_y_items(char **tab, char c);
int		send_error_message(t_data *data);
int		flood_fill(t_data *data);
void    start_game(t_data *data);
void	fill_data(t_data *data);
void 	put_exit(t_data *data);
void 	put_items(t_data *data);
void 	put_walls(t_data *data);
void 	put_background(t_data *data);
void 	put_player(t_data *data);
void	destroy_all(t_data *data);
void	destroy_first(t_data *data);
void	put_exit(t_data *data);
void	put_player(t_data *data);
void	put_items(t_data *data);
void	put_walls(t_data *data);
void	put_background(t_data *data);
void	up_pressed(t_data *data);
void	down_pressed(t_data *data);
void	right_pressed(t_data *data);
void	left_pressed(t_data *data);
void	esc_pressed(t_data *data);
int		check_update(void *d);
void	replace_in_tab(t_data *data, int x, int y);
void	replace_w_background(t_data *data);
void	create_map(t_data *data);
int key_hook(int key, void* d);
int key_hook_up(int key, void* d);
int windows_hook(int event, void* param);






#endif