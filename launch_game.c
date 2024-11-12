/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:03:01 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/12 19:03:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void *init_background(void *mlx)
{
	void *img;
	int	w;
	
	w = 50;
    img = mlx_jpg_file_to_image(mlx, "textures/background.jpg", &w, &w);
	return (img);
}

void    start_game(t_data *data)
{
    void *mlx;
	void *win;
	int x;
	
	x = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "so_long");
    void *img = init_background(mlx);
	while (x < 10)
	{
		mlx_put_image_to_window(mlx, win, img, x * 50, 0);	
		x++;
	}
	mlx_loop(mlx);
	
	(void)data;
	mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
}

