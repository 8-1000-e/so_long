/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_graphic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:55:13 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/14 01:02:10 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_first(t_data *data)
{
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->walls);
}
void	destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->items);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}