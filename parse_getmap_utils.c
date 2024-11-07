/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:35:57 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/07 17:44:44 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	send_error_message(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	write(2, "Error\n", 6);
	write(2, "Bad map configuration\n", 22);
	return (0);
}

int	get_x_start(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y] != 'P' && tab[x][y])
			y++;
		if (tab[x][y] == 'P')
			return (x);
		x++;
	}
	return (-1);
}

int	get_y_start(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y] != 'P' && tab[x][y])
			y++;
		if (tab[x][y] == 'P')
			return (y);
		x++;
	}
	return (-1);
}

int	tab_len(char **tab)
{
	int	c;

	c = 0;
	while (*tab++)
		c++;
	return (c);
}

int	nb_line(char **tab)
{
	int	c;

	c = 0;
	while (*tab++)
		c++;
	return (c);
}
