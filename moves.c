/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:23 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 04:34:14 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_map *map)
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
	ft_putnbr_fd(map->movement, 1);
	ft_putstr_fd(": up\n", 1);
	map->movement++;
}

void	down(t_map *map)
{
	if (map->split_map[map->p1 + 1][map->p2] == '1')
		return ;
	if (map->split_map[map->p1 + 1][map->p2] == 'E'
		&& map->coin_nbr != 0)
		return ;
	if (map->split_map[map->p1 + 1][map->p2] == 'E'
		&& map->coin_nbr == 0)
		exit(0);
	if (map->split_map[map->p1 + 1][map->p2] == 'C')
	{
		map->split_map[map->p1 + 1][map->p2] = 'P';
		map->split_map[map->p1][map->p2] = '0';
		map->coin_nbr--;
	}
	else
	{
		map->split_map[map->p1 + 1][map->p2] = 'P';
		map->split_map[map->p1][map->p2] = '0';
	}
	ft_putnbr_fd(map->movement, 1);
	ft_putstr_fd(": down\n", 1);
	map->movement++;
}

void	right(t_map *map)
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
	ft_putnbr_fd(map->movement, 1);
	ft_putstr_fd(": right\n", 1);
	map->movement++;
}

void	left(t_map *map)
{
	if (map->split_map[map->p1][map->p2 - 1] == '1')
		return ;
	if (map->split_map[map->p1][map->p2 - 1] == 'E'
		&& map->coin_nbr != 0)
		return ;
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
	ft_putnbr_fd(map->movement, 1);
	ft_putstr_fd(": left\n", 1);
	map->movement++;
}

int	keybord(int key, t_map *map)
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
