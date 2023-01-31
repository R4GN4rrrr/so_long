/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:57:43 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 04:44:33 by ymenyoub         ###   ########.fr       */
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
	int	i;
	int	l;
	int	j;

	i = 0;
	j = 0;
	l = ft_strlen(map->split_map[0]) - 1;
	while (map->split_map[0][j])
	{
		if (map->split_map[0][j] != '1')
			print_error("invalid map!");
		j++;
	}
	while (map->split_map[i])
	{
		if (map->split_map[i][0] != '1')
			print_error("invalid map!");
		if (map->split_map[i][l] != '1')
			print_error("invalid map!");
		i++;
	}
	j = 0;
	while (map->split_map[i - 1][j])
	{
		if (map->split_map[i - 1][j] != '1')
			print_error("invalid map!");
		j++;
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
