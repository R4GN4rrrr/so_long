/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:57:43 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/30 03:42:54 by ymenyoub         ###   ########.fr       */
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
}

void	check_composed(t_map *map)
{
	int i = 0;

	while (map->str[i])
	{
		if (map->str[i] != '0' && map->str[i] != '1'
			&& map->str[i] != '\n' && map->str[i] != 'P'
			&& map->str[i] != 'C' && map->str[i] != 'E')
			print_error("Stranger element");
		i++;
	}
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

void	check_rectangular(t_map *map)
{
	int i = 1;
	size_t l = ft_strlen(map->split_map[0]);
	while (map->split_map[i])
	{
		if (ft_strlen(map->split_map[i]) != l)
			print_error("The map must be rectangular");
		i++;
	}
}

void	check_Walls(t_map *map)
{
	int i = 0;
	int	l = ft_strlen(map->split_map[0]) - 1;
	int j = 0;
	while (map->split_map[0][j])
	{
		if (map->split_map[0][j] != '1')
			print_error("inva1");
		j++;
	}
	while (map->split_map[i])
	{
		if (map->split_map[i][0] != '1')
			print_error("inva2");
		if (map->split_map[i][l] != '1')
			print_error("inva3");
		i++;
	}
	j = 0;
	while (map->split_map[i - 1][j])
	{
		if (map->split_map[i - 1][j] != '1')
			print_error("inva4");
		j++;
	}
}
void	check_body(t_map *map)
{
	int i = 0;

	if (map->str[i] != '1')
		print_error("something_wrong");
	while (map->str[i])
	{
		if (map->str[i] == '\n' && map->str[i + 1] != '1')
			print_error("there is new line");
		i++;
	}
}
void	check(t_map *map)
{
	check_composed(map);
	check_items(map);
	check_rectangular(map);
	check_Walls(map);
	check_body(map);
	find_palyer(map);
	flood_fill_player(map->p2, map->p1, map->split_map);
	flood_fill_exit(map->p2, map->p1, map->split_map);
}