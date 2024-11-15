/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:03:01 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/15 01:20:36 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void create_map(t_data *data)
{
	put_background(data);
	put_walls(data);
	put_items(data);
	put_player(data);
	put_exit(data);
}


void	replace_w_background(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win ,data->background, data->p.y * 48, data->p.x * 48);
}

void	replace_in_tab(t_data *data, int x, int y)
{
	data->map[x][y] = '0';
}

int	check_update(void *d)
{
	t_data	*data;
	int		i;
	int		old_nb_moove;
	
	data = (t_data *)d;
	old_nb_moove = data->nb_moove;
	i = 0 ;
	if (data->pressed[SDL_SCANCODE_W] || data->pressed[SDL_SCANCODE_UP])
		up_pressed(data);
	if (data->pressed[SDL_SCANCODE_A] || data->pressed[SDL_SCANCODE_LEFT])
		left_pressed(data);
	if (data->pressed[SDL_SCANCODE_S] || data->pressed[SDL_SCANCODE_DOWN])
		down_pressed(data);
	if (data->pressed[SDL_SCANCODE_D] || data->pressed[SDL_SCANCODE_RIGHT])
		right_pressed(data);
	if (data->pressed[SDL_SCANCODE_ESCAPE])
		esc_pressed(data);
	if (old_nb_moove != data->nb_moove)
		ft_printf("%d\n", data->nb_moove);
	return (0);
}

void    start_game(t_data *data)
{
	fill_data(data);
	create_map(data);

    mlx_on_event(data->mlx, data->win, MLX_KEYDOWN, key_hook, data);
    mlx_on_event(data->mlx, data->win, MLX_KEYUP, key_hook_up, data);
	mlx_on_event(data->mlx, data->win, MLX_WINDOW_EVENT, windows_hook, data);
	
	mlx_loop_hook(data->mlx, check_update, data);

	mlx_set_fps_goal(data->mlx, 10);
	mlx_loop(data->mlx);
	
	destroy_first(data);
	destroy_all(data);
}


