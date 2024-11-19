/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:19:38 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/19 22:03:59 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	up_pressed(t_data *data)
{
	if (data->map[data->p.x - 1][data->p.y] != '1')
	{
		data->nb_moove++;
		replace_w_img(data, data->p.x * 48, data->p.y* 48, data->background);
		if (data->map[data->p.x - 1][data->p.y] == 'C')
		{	
			data->items_picked++;
			replace_in_tab(data, data->p.x - 1, data->p.y, '0');	
		}
		if (data->map[data->p.x - 1][data->p.y] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		replace_in_tab(data, data->p.x, data->p.y, '0');
		data->p.x -= 1;
		replace_in_tab(data, data->p.x, data->p.y, 'P');
		put_player(data);
		check_for_rhino(data);
	}
}

void	down_pressed(t_data *data)
{
	if (data->map[data->p.x + 1][data->p.y] != '1')
	{
		data->nb_moove++;
		replace_w_img(data, data->p.x* 48, data->p.y* 48, data->background);
		if (data->map[data->p.x + 1][data->p.y] == 'C')
		{	
			data->items_picked++;
			replace_in_tab(data, data->p.x + 1, data->p.y, '0');
		}
		if (data->map[data->p.x + 1][data->p.y] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		replace_in_tab(data, data->p.x, data->p.y, '0');
		data->p.x += 1;
		replace_in_tab(data, data->p.x, data->p.y, 'P');
		put_player(data);
		check_for_rhino(data);
	}
}
void	left_pressed(t_data *data)
{
	if (data->map[data->p.x][data->p.y - 1] != '1')
	{
		data->nb_moove++;
		replace_w_img(data, data->p.x* 48, data->p.y* 48, data->background);
		if (data->map[data->p.x][data->p.y - 1] == 'C')
			{
				replace_in_tab(data, data->p.x, data->p.y - 1, '0');
				data->items_picked++;
			}
		if (data->map[data->p.x][data->p.y - 1] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		replace_in_tab(data, data->p.x, data->p.y, '0');
		data->p.y -= 1;
		replace_in_tab(data, data->p.x, data->p.y, 'P');
		put_player(data);
		check_for_rhino(data);
	}
}


void	right_pressed(t_data *data)
{
	if (data->map[data->p.x][data->p.y + 1] != '1')
	{
		data->nb_moove++;
		replace_w_img(data, data->p.x* 48, data->p.y* 48, data->background);
		if (data->map[data->p.x][data->p.y + 1] == 'C')
		{
			data->items_picked++;
			replace_in_tab(data, data->p.x, data->p.y + 1, '0');
		}
		if (data->map[data->p.x][data->p.y + 1] == 'E' && data->nb_items == data->items_picked)
			mlx_loop_end(data->mlx);
		replace_in_tab(data, data->p.x, data->p.y, '0');
		data->p.y += 1;
		replace_in_tab(data, data->p.x, data->p.y, 'P');
		put_player(data);
		check_for_rhino(data);
	}
}

void	esc_pressed(t_data *data)
{
	mlx_loop_end(data->mlx);
}