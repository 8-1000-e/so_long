/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:59:01 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/18 04:51:48 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	parse_opposed_line(char *line)
{
	if (!line)
		return (0);
	while (*line == '1')
		line++;
	if (!*line || *line == '\n')
		return (1);
	return (0);
}

static int	parse_body_line(char *line)
{
	if (!line)
		return (0);
	while (*line && ft_strchr("01CEP\n", *line))
		line++;
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		return (0);
	if (!*line)
		return (1);
	return (0);
}

int	get_parsed_map(char **tab, t_data *data)
{
	int	nb_lines;

	nb_lines = data->max_y + 1;
	if (!parse_opposed_line(tab[0]) && !parse_opposed_line(tab[data->max_x]))
		return (0);
	tab += 1;
	nb_lines -= 2;
	while (nb_lines-- && parse_body_line(*tab))
		tab++;
	if (!check_format(data->map) || !find_exit(data) || !find_start(data))
		return (0);
	return (1);
}
