/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:42:44 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/15 01:26:34 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void put_background(t_data *data)
{
	int x;
	int	y;
	
	x = 0;
	while (x < data->max_x)
	{
		y = 0;
		while (y < data->max_y)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->background, y * 48, x * 48);	
			y++;
		}
		x++;
	}
}

void put_walls(t_data *data)
{
	int x;
	int	y;
	
	x = 0;
	while (x < data->max_x)
	{
		y = 0;
		while (y < data->max_y)
		{
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->walls, y * 48, x * 48);	
			y++;
		}
		x++;
	}
}

void put_items(t_data *data)
{
	int x;
	int	y;
	
	x = 0;
	while (x < data->max_x)
	{
		y = 0;
		while (y < data->max_y)
		{
			if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->items, y * 48, x * 48);	
			y++;
		}
		x++;
	}
}

void put_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->player, data->p.y * 48,data->p.x * 48);
}

void put_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->exit, data->e.y * 48,data->e.x * 48);
}