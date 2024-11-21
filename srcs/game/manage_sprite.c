/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:14:44 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/21 17:29:23 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	change_sprit(t_data *data)
{
	if (data->map[data->p.x - 1][data->p.y - 1] == 'C')
		return (1);
	if (data->map[data->p.x - 1][data->p.y + 1] == 'C')
		return (1);
	if (data->map[data->p.x - 1][data->p.y] == 'C')
		return (1);
	if (data->map[data->p.x][data->p.y - 1] == 'C')
		return (1);
	if (data->map[data->p.x][data->p.y + 1] == 'C')
		return (1);
	if (data->map[data->p.x][data->p.y] == 'C')
		return (1);
	if (data->map[data->p.x + 1][data->p.y - 1] == 'C')
		return (1);
	if (data->map[data->p.x + 1][data->p.y + 1] == 'C')
		return (1);
	if (data->map[data->p.x + 1][data->p.y] == 'C')
		return (1);
	return (0);
}
