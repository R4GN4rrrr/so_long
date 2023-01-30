#include <mlx.h>
#include <stdio.h>
#include "so_long.h"
int quit()
{
	exit(0);
	return (0);
}

void    ft_show_in_map(t_map *map)
{
	int i;
	int j = 0;
	int x;
	int y;
	int l = 0, k = 0;

	map->player = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/player.xpm", &x, &y);
	map->ground = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/floor.xpm", &x, &y);
	map->coin = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/collect_.xpm", &x, &y);
	map->o_door = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/open_exit.xpm", &x, &y);
	map->c_door = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/closed_exit.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/wall.xpm", &x, &y);

	if (!map->player || !map->ground || !map->coin || !map->o_door || !map->c_door || !map->wall)
	{
		print_error("Invalid img");
		exit(1);
	}

	i = 0;
	while (map->split_map[i])
	{
		j = 0;
		l = 0;
		while (map->split_map[i][j])
		{
			if (map->split_map[i][j] == '1')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall, l, k);
			}
			if (map->split_map[i][j] == 'C')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground, l, k);
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->coin, l, k);
			}
			if (map->split_map[i][j] == 'E')
			{
				if (map->coin_nbr == 0)
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->o_door, l, k);
				else
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->c_door, l, k);
			}
			if (map->split_map[i][j] == '0')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground, l, k);
			}
			if (map->split_map[i][j] == 'P')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground, l, k);
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player, l, k);
			}
			l += 70;
			j++;
		}
		k += 70;
		i++;
	}
}
int main(int ac, char **av)
{
	t_map map;
	map.coin_nbr = 0;
	map.movement = 0;
	if (ac == 2)
	{
		map.move_nbr = 0;
		map.mlx_ptr = mlx_init();
		map.fd = open(av[1], O_RDWR, 0777);
		if (map.fd == -1)
			return 0;
		readmap(&map);
		check(&map);
		coin_nbr(&map);
		map.win_ptr = mlx_new_window(map.mlx_ptr, width_map(&map) * 70, lenght_map(&map) * 70, "so_long");
		mlx_hook(map.win_ptr, 2, 0,keybord, &map);
		ft_show_in_map(&map);
		mlx_hook(map.win_ptr, 17, 0, quit, &map);
		mlx_loop(map.mlx_ptr);
	}
	else 
		printf("Not enough of args!");
}
