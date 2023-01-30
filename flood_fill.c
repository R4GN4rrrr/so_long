/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:33:40 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/30 03:43:15 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_player(int pos_x, int pos_y, char **map)
{
	int i = 0, j;
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == 'E'
		|| map[pos_y][pos_x] == 'F')
		return ;
	map[pos_y][pos_x] = 'F';
	flood_fill_player(pos_x + 1, pos_y, map);
	flood_fill_player(pos_x, pos_y + 1, map);
	flood_fill_player(pos_x, pos_y - 1, map);
	flood_fill_player(pos_x - 1, pos_y, map);
	while (map[i])
	{
		//exit(printf("here\n"));
		printf("%s\n", map[i]);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E' && map[i][j] != 'F')
			{
				write(2, "Ivalid path\n", 12);
				exit(1);
			}
			j++;
		}
		i++;
	}
 }

void	flood_fill_exit(int pos_x, int pos_y, char **map)
{
	int i = 0, j;
	if (map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'F'
		&& map[pos_y][pos_x] != 'E')
		return ;
	map[pos_y][pos_x] = 'I';
	flood_fill_exit(pos_x + 1, pos_y, map);
	flood_fill_exit(pos_x, pos_y + 1, map);
	flood_fill_exit(pos_x, pos_y - 1, map);
	flood_fill_exit(pos_x - 1, pos_y, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'I')
			{
				write(2, "Invalid map\n", 12);
				exit(1);
			}
			j++;
		}
		i++;
	}
}