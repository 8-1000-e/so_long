/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:20:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/15 01:26:49 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int key_hook(int key, void* d)
{
	t_data *data;

	data = d;
	data->pressed[key] = 1;	
    return (0);
}

int key_hook_up(int key, void* d)
{
	t_data *data;

	data = d;
	data->pressed[key] = 0;
    return (0);
}

int windows_hook(int event, void* param)
{
	if (!event)
		mlx_loop_end(param);
	return (0);
}