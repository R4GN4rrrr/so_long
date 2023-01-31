/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:55:10 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 04:38:32 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lenght_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->split_map[i])
		i++;
	return (i);
}

int	width_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->split_map[0][i])
		i++;
	return (i);
}

void	coin_nbr(t_map *map)
{
	int	i;

	i = 0;
	while (map->str[i])
	{
		if (map->str[i] == 'C')
			map->coin_nbr++;
		i++;
	}
}

void	find_palyer(t_map *map)
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

int	quit(void)
{
	exit(0);
	return (0);
}
