/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:57:43 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 05:12:24 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	readmap(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	map->str = ft_calloc(1, 1);
	if (line == NULL)
		exit(0);
	while (line)
	{
		map->str = ft_strjoin(map->str, line);
		free(line);
		line = get_next_line(map->fd);
	}
	map->split_map = ft_split(map->str, '\n');
	map->dup_map = ft_split(map->str, '\n');
}

void	check_items(t_map *map)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	map->collect = 0;
	while (map->str[i])
	{
		if (map->str[i] == 'C')
			map->collect += 1;
		if (map->str[i] == 'P')
			p += 1;
		if (map->str[i] == 'E')
			e += 1;
		i++;
	}
	if (p != 1)
		print_error("The map must contain  1 starting position");
	if (e != 1)
		print_error("The map must contain 1 exit");
	if (map->collect < 1)
		print_error("The map must contain at least 1 collectible!");
}

void	check_walls(t_map *map)
{
	t_vars	var;

	var.a = 0;
	var.b = 0;
	var.c = ft_strlen(map->split_map[0]) - 1;
	while (map->split_map[0][var.b])
	{
		if (map->split_map[0][var.b] != '1')
			print_error("invalid map!");
		var.b++;
	}
	while (map->split_map[var.a])
	{
		if (map->split_map[var.a][0] != '1')
			print_error("invalid map!");
		if (map->split_map[var.a][var.c] != '1')
			print_error("invalid map!");
		var.a++;
	}
	var.b = -1;
	while (map->split_map[var.a - 1][++var.b])
	{
		if (map->split_map[var.a - 1][var.b] != '1')
			print_error("invalid map!");
	}
}

void	check(t_map *map)
{
	check_composed(map);
	check_items(map);
	check_rectangular(map);
	check_walls(map);
	check_body(map);
	find_palyer(map);
	ft_help1(map);
	ft_help2(map);
}
