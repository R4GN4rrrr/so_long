/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:23 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/29 19:00:13 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//this fonction find the player position
void    find_palyer(t_map *map)
{
	map->p1 = 0;
	while (map->split_map[map->p1])
	{
		map->p2 = 0;
		while (map->split_map[map->p1][map->p2])
		{
			if (map->split_map[map->p1][map->p2] == 'P')
				return ;
			map->p2++;
		}
		map->p1++;
	}
}

//this fonction check the nbr of collect in the map
void    coin_nbr(t_map *map)
{
	int i;

	i = 0;
	while (map->str[i])
	{
		if (map->str[i] == 'C')
			map->coin_nbr++;
		i++;
	}
}
//this fonction move the player "up" and swap it in the map 
void    up(t_map *map)
{
	if (map->split_map[map->p1 - 1][map->p2] == '1')
		return ;
	if (map->split_map[map->p1 - 1][map->p2] == 'E'
		&& map->coin_nbr != 0)
		return ;
	 if (map->split_map[map->p1 - 1][map->p2] == 'E'
		&& map->coin_nbr == 0)
		exit(0);
	if (map->split_map[map->p1 - 1][map->p2] == 'C')
	{
		map->split_map[map->p1 - 1][map->p2] = 'P';
		map->split_map[map->p1][map->p2] = '0';
		map->coin_nbr--;
	}
	else
	{
		map->split_map[map->p1 - 1][map->p2] = 'P';
		map->split_map[map->p1][map->p2] = '0';
	}
	map->movement++;
}

void    down(t_map *map)
{
	if (map->split_map[map->p1+ 1][map->p2] == '1')
		return ;
	if (map->split_map[map->p1+ 1][map->p2] == 'E'
		&& map->coin_nbr != 0)
		return ;
	if (map->split_map[map->p1 + 1][map->p2] == 'E'
		&& map->coin_nbr == 0)
		exit(0);
	if (map->split_map[map->p1+ 1][map->p2] == 'C')
	{
		map->split_map[map->p1+ 1][map->p2] = 'P';
		map->split_map[map->p1][map->p2] = '0';
		map->coin_nbr--;
	}
	else
	{
		map->split_map[map->p1+ 1][map->p2] = 'P';
		map->split_map[map->p1][map->p2] = '0';
	}
	map->movement++;
}

void    right(t_map *map)
{
	if (map->split_map[map->p1][map->p2 + 1] == '1')
		return ;
	if (map->split_map[map->p1][map->p2 + 1] == 'E'
		&& map->coin_nbr != 0)
		return ;
	if (map->split_map[map->p1][map->p2 + 1] == 'E'
		&& map->coin_nbr == 0)
		exit(0);
	if (map->split_map[map->p1][map->p2 + 1] == 'C')
	{
		map->split_map[map->p1][map->p2 + 1] = 'P';
		map->split_map[map->p1][map->p2] = '0';
		map->coin_nbr--;
	}
	else
	{
		map->split_map[map->p1][map->p2 + 1] = 'P';
		map->split_map[map->p1][map->p2] = '0';
	}
	map->movement++;
}

void    left(t_map *map)
{
	if (map->split_map[map->p1][map->p2 - 1] == '1')
		return ;
	if (map->split_map[map->p1][map->p2 - 1] == 'E'
		&& map->coin_nbr != 0)
	if (map->split_map[map->p1][map->p2 - 1] == 'E'
		&& map->coin_nbr == 0) 
		exit(0);
	if (map->split_map[map->p1][map->p2 - 1] == 'C')
	{
		map->split_map[map->p1][map->p2 - 1] = 'P';
		map->split_map[map->p1][map->p2] = '0';
		map->coin_nbr--;
	}
	else
	{
		map->split_map[map->p1][map->p2 - 1] = 'P';
		map->split_map[map->p1][map->p2] = '0';
	}
	map->movement++;
}

int keybord(int key, t_map *map)
{
	if (key == 126 || key == 13)
	{
		find_palyer(map);
		up(map);
	}
	if (key == 125 || key == 1)
	{
		find_palyer(map);
		down(map);
	}
	if (key == 124 || key == 2)
	{
	   find_palyer(map);
	   right(map);
	}
	if (key == 123 || key == 0)
	{
	   find_palyer(map);
	   left(map);
	}
	ft_show_in_map(map);
	if (key == 53)
		exit(0);
	return (0);
}