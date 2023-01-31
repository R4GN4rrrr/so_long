/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:02:41 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 04:51:25 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(t_map *map, int l, int k)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall, l, k);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		15, 15, 0xFFFFF0, ft_itoa(map->movement));
}

void	coin(t_map *map, int l, int k)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground, l, k);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->coin, l, k);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		15, 15, 0xFFFFF0, ft_itoa(map->movement));
}

void	dooor(t_map *map, int l, int k)
{
	if (map->coin_nbr == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->o_door, l, k);
	else
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->c_door, l, k);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		15, 15, 0xFFFFF0, ft_itoa(map->movement));
}

void	zero(t_map *map, int l, int k)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground, l, k);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		15, 15, 0xFFFFF0, ft_itoa(map->movement));
}

void	player(t_map *map, int l, int k)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground, l, k);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player, l, k);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		15, 15, 0xFFFFF0, ft_itoa(map->movement));
}
