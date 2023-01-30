/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:54:58 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/30 02:01:18 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name(char *name)
{
	if (ft_strncmp(name + (ft_strlen(name) - 4), ".ber", 4))
		return (1);
	return (0);
}

void print_error(char *s)
{
		ft_putstr_fd ("Error\n", 2);
		ft_putstr_fd(s, 2);
		exit(0);
}
