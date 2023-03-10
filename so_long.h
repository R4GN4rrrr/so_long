/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:35:26 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/31 05:25:22 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_vars
{
	int	a;
	int	b;
	int	c;
	int	l;
	int	k;
	int	m;
	int	n;
}	t_vars;

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	char	*str;
	int		fd;
	char	**split_map;
	int		pos_x;
	int		pos_y;
	int		collect;
	int		movement;
	void	*player;
	void	*ground;
	void	*coin;
	void	*o_door;
	void	*c_door;
	void	*wall;
	int		move_nbr;
	int		coin_nbr;
	int		p1;
	int		p2;
	char	**dup_map;
}	t_map;

char	*ft_add_join(int fd, char *saved);
char	*ft_line(char *string);
char	*ft_rest(char *save);
char	*get_next_line(int fd);
size_t	ft_strl(char *s);
char	*ft_strd(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strch(char *s);
void	readmap(t_map *map);
void	check(t_map *map);
void	print_error(char *s);
int		width_map(t_map *map);
int		lenght_map(t_map *map);
int		keybord(int key, t_map *map);
void	coin_nbr(t_map *map);
void	ft_show_in_map(t_map *map);
void	flood_fill_player(int pos_x, int pos_y, char **map);
void	flood_fill_exit(int pos_x, int pos_y, char **map);
void	find_palyer(t_map *map);
void	player(t_map *map, int l, int k);
void	zero(t_map *map, int l, int k);
void	dooor(t_map *map, int l, int k);
void	coin(t_map *map, int l, int k);
void	wall(t_map *map, int l, int k);
int		quit(void);
void	ft_help2(t_map *tmap);
void	ft_help1(t_map *tmap);
void	check_rectangular(t_map *map);
void	check_composed(t_map *map);
void	check_body(t_map *map);
void	coin_nbr(t_map *map);
#endif