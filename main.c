/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:24:13 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/07 19:00:49 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**map;
	int		fd;

	if (ac > 2)
		write(2, "Error\n", 6);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (send_error_message(NULL));
	map = get_map(fd);
	if (!map)
		return (send_error_message(NULL));
	getdata(&data, map);
	if (!check_data(&data) || !get_parsed_map(map, &data))
		return (send_error_message(&data));
	return (free_map(map));
	
}