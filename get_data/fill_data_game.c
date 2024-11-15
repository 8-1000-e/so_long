/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:32:56 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/14 23:33:11 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void *init(void *mlx, char *s)
{
	void *img;
	int	w;
	
	w = 48;
    img = mlx_png_file_to_image(mlx, s, &w, &w);
	return (img);
}

void	fill_data(t_data *data)
{
	data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, (data->max_y - 1) * 48, data->max_x * 48, "so_long");
	data->background = init(data->mlx, "textures/background.png");
	data->walls = init(data->mlx, "textures/walls.png");
	data->items = init(data->mlx, "textures/items.png");
	data->player = init(data->mlx, "textures/player/player_sprite_2.png");
	data->exit = init(data->mlx, "textures/exit.png");
}