/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:42:53 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 05:33:46 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	pictures(t_map *map)
{
	int	x;
	int	y;

	map->player = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/player.xpm", &x, &y);
	map->ground = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/floor.xpm", &x, &y);
	map->coin = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/collect_.xpm", &x, &y);
	map->o_door = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/open_exit.xpm", &x, &y);
	map->c_door = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/closed_exit.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/wall.xpm", &x, &y);
	if (!map->player || !map->ground || !map->coin
		|| !map->o_door || !map->c_door || !map->wall)
	{
		print_error("Invalid img");
		exit(1);
	}
}

void	ft_show_in_map(t_map *map)
{
	t_vars	var;

	pictures(map);
	var.m = -1;
	var.k = 0;
	while (map->split_map[++var.m])
	{
		var.n = -1;
		var.l = 0;
		while (map->split_map[var.m][++var.n])
		{
			if (map->split_map[var.m][var.n] == '1')
				wall(map, var.l, var.k);
			if (map->split_map[var.m][var.n] == 'C')
				coin(map, var.l, var.k);
			if (map->split_map[var.m][var.n] == 'E')
				dooor(map, var.l, var.k);
			if (map->split_map[var.m][var.n] == '0')
				zero(map, var.l, var.k);
			if (map->split_map[var.m][var.n] == 'P')
				player(map, var.l, var.k);
			var.l += 70;
		}
		var.k += 70;
	}
}

int	main(int ac, char **av)
{
	t_map	map;

	map.coin_nbr = 0;
	map.movement = 1;
	if (ac == 2)
	{
		map.move_nbr = 0;
		map.mlx_ptr = mlx_init();
		map.fd = open(av[1], O_RDWR, 0777);
		if (map.fd == -1)
			return (0);
		readmap(&map);
		check(&map);
		coin_nbr(&map);
		map.win_ptr = mlx_new_window(map.mlx_ptr, width_map(&map) * 70,
				lenght_map(&map) * 70, "so_long");
		mlx_hook(map.win_ptr, 2, 0, keybord, &map);
		ft_show_in_map(&map);
		mlx_hook(map.win_ptr, 17, 0, quit, &map);
		mlx_loop(map.mlx_ptr);
	}
	else
		ft_putstr_fd("Not enough of args!", 2);
}
