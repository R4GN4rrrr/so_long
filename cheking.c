/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:54:58 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 04:19:53 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name(char *name)
{
	if (ft_strncmp(name + (ft_strlen(name) - 4), ".ber", 4))
		return (1);
	return (0);
}

void	print_error(char *s)
{
	ft_putstr_fd ("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(0);
}

void	check_rectangular(t_map *map)
{
	int		i;
	size_t	l;

	i = 1;
	l = ft_strlen(map->split_map[0]);
	while (map->split_map[i])
	{
		if (ft_strlen(map->split_map[i]) != l)
			print_error("The map must be rectangular");
		i++;
	}
}

void	check_composed(t_map *map)
{
	int	i;

	i = 0;
	while (map->str[i])
	{
		if (map->str[i] != '0' && map->str[i] != '1'
			&& map->str[i] != '\n' && map->str[i] != 'P'
			&& map->str[i] != 'C' && map->str[i] != 'E')
			print_error("Stranger element");
		i++;
	}
}

void	check_body(t_map *map)
{
	int	i;

	i = 0;
	if (map->str[i] != '1')
		print_error("something_wrong");
	while (map->str[i])
	{
		if (map->str[i] == '\n' && map->str[i + 1] != '1')
			print_error("there is new line");
		i++;
	}
}
