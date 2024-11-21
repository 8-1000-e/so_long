/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_graphic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:55:13 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/21 17:26:04 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	destroy_numbers(t_data *data)
{
	int	i;

	i = 9;
	while (i)
		mlx_destroy_image(data->mlx, data->numbers[i--]);
	mlx_destroy_image(data->mlx, data->numbers[0]);
}

void	destroy_first(t_data *data)
{
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player[0]);
	mlx_destroy_image(data->mlx, data->player[1]);
	mlx_destroy_image(data->mlx, data->walls);
	mlx_destroy_image(data->mlx, data->rhino);
}

void	destroy_all(t_data *data)
{
	destroy_numbers(data);
	destroy_first(data);
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->items);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}
