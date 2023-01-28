/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:23 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/28 23:47:28 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
void    up(t_map *map)
{
    if (map->split_map[map->pos_y - 1][map->pos_x] == '1')
        return ;
    if (map->split_map[map->pos_y - 1][map->pos_x] == 'E'
        && map->collect != 0)
        return ;
    if (map->split_map[map->pos_y - 1][map->pos_x] == 'C')
    {
        map->split_map[map->pos_y - 1][map->pos_x] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_y--;
        map->coin_nbr--;
    }
    else
        map->split_map[map->pos_y - 1][map->pos_x] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_y--;
    map->movement++;
}

void    down(t_map *map)
{
    if (map->split_map[map->pos_y + 1][map->pos_x] == '1')
        return ;
    if (map->split_map[map->pos_y + 1][map->pos_x] == 'E'
        && map->collect != 0)
        return ;
    if (map->split_map[map->pos_y + 1][map->pos_x] == 'C')
    {
        map->split_map[map->pos_y + 1][map->pos_x] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_y++;
        map->collect--;
    }
    else
        map->split_map[map->pos_y + 1][map->pos_x] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_y++;
    map->movement++;
}

void    right(t_map *map)
{
    if (map->split_map[map->pos_y][map->pos_x + 1] == '1')
        return ;
    if (map->split_map[map->pos_y][map->pos_x + 1] == 'E'
        && map->collect != 0)
        return ;
    if (map->split_map[map->pos_y][map->pos_x + 1] == 'C')
    {
        map->split_map[map->pos_y][map->pos_x + 1] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_x++;
        map->collect--;
    }
    else
        map->split_map[map->pos_y][map->pos_x + 1] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_x++;
    map->movement++;
}

void    left(t_map *map)
{
    if (map->split_map[map->pos_y][map->pos_x - 1] == '1')
        return ;
    if (map->split_map[map->pos_y][map->pos_x - 1] == 'E'
        && map->collect != 0)
        return ;
    if (map->split_map[map->pos_y][map->pos_x - 1] == 'C')
    {
        map->split_map[map->pos_y][map->pos_x - 1] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_x--;
        map->collect--;
    }
    else
        map->split_map[map->pos_y][map->pos_x - 1] = 'P';
        map->split_map[map->pos_y][map->pos_x] = '0';
        map->pos_x--;
    map->movement++;
}

int keybord(int key, t_map *map)
{
    if (key == 126 || key == 13)
        up(map);
    if (key == 125 || key == 1)
        down(map);
    if (key == 124 || key == 2)
        right(map);
    if (key == 123 || key == 0)
        left(map);
    return (0);
}