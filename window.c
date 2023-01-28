/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:55:10 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/27 17:05:50 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    img(t_show *win, char *path)
{
    win->img = mlx_xpm_file_to_image(win->mlx_ptr, path, 70, 70);
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img, 10, 10);
}

void    init(t_show *win)
{
    win->mlx_ptr = mlx_new_window(win->mlx_ptr, 500, 500, "fir3aaawn"); 
}

void    show(t_map *map)
{
    if ()

}
