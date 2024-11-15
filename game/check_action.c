/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:19:38 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/15 01:26:39 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up_pressed(t_data *data)
{
	data->nb_moove++;
	if (data->map[data->p.x - 1][data->p.y] != '1')
	{
		replace_w_background(data);
		if (data->map[data->p.x - 1][data->p.y] == 'C')
		{	
			data->items_picked++;
			replace_in_tab(data, data->p.x - 1, data->p.y);	
		}
		if (data->map[data->p.x - 1][data->p.y] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		data->p.x -= 1;
		put_player(data);
	}
}

void	down_pressed(t_data *data)
{
	data->nb_moove++;
	if (data->map[data->p.x + 1][data->p.y] != '1')
	{
		replace_w_background(data);
		if (data->map[data->p.x + 1][data->p.y] == 'C')
		{	
			data->items_picked++;
			replace_in_tab(data, data->p.x + 1, data->p.y);
		}
		if (data->map[data->p.x + 1][data->p.y] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		data->p.x += 1;
		put_player(data);
	}
}
void	left_pressed(t_data *data)
{
	data->nb_moove++;
	if (data->map[data->p.x][data->p.y - 1] != '1')
	{
		replace_w_background(data);
		if (data->map[data->p.x][data->p.y - 1] == 'C')
			{
				replace_in_tab(data, data->p.x, data->p.y - 1);
				data->items_picked++;
			}
		if (data->map[data->p.x][data->p.y - 1] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		data->p.y -= 1;
		put_player(data);
	}
}

void	right_pressed(t_data *data)
{
	data->nb_moove++;
	if (data->map[data->p.x][data->p.y + 1] != '1')
	{
		replace_w_background(data);
		if (data->map[data->p.x][data->p.y + 1] == 'C')
		{
			data->items_picked++;
			replace_in_tab(data, data->p.x, data->p.y + 1);
		}
		if (data->map[data->p.x][data->p.y + 1] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		data->p.y += 1;
		put_player(data);
	}
}

void	esc_pressed(t_data *data)
{
	mlx_loop_end(data->mlx);
}