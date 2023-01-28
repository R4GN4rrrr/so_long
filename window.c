/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:55:10 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/28 01:27:01 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int lenght_map(t_map *map)
{
    int i;

    i = 0;
    while (map->split_map[i])
        i++;
    return (i);
}

int width_map(t_map *map)
{
    int i;

    i = 0;
    while (map->split_map[0][i])
        i++;
    return (i);
}
