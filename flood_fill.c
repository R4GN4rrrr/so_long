/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:33:40 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 04:22:45 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_player(int pos_x, int pos_y, char **map)
{
	if (map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'C'
		&& map[pos_y][pos_x] != 'P')
		return ;
	map[pos_y][pos_x] = 'F';
	flood_fill_player(pos_x + 1, pos_y, map);
	flood_fill_player(pos_x, pos_y + 1, map);
	flood_fill_player(pos_x, pos_y - 1, map);
	flood_fill_player(pos_x - 1, pos_y, map);
}

void	flood_fill_exit(int pos_x, int pos_y, char **map)
{
	if (map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'F'
		&& map[pos_y][pos_x] != 'E')
		return ;
	map[pos_y][pos_x] = 'I';
	flood_fill_exit(pos_x + 1, pos_y, map);
	flood_fill_exit(pos_x, pos_y + 1, map);
	flood_fill_exit(pos_x, pos_y - 1, map);
	flood_fill_exit(pos_x - 1, pos_y, map);
}

void	ft_help1(t_map *tmap)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = tmap->dup_map;
	flood_fill_player(tmap->p2, tmap->p1, tmap->dup_map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				write(2, "Ivalid path\n", 12);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_help2(t_map *tmap)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = tmap->dup_map;
	flood_fill_exit(tmap->p2, tmap->p1, tmap->dup_map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				write(2, "Invalid map2\n", 12);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
