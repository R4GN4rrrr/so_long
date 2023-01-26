/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 04:24:40 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/23 18:07:45 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strd(char *s1)
{
	size_t	l;
	size_t	i;
	char	*p;

	i = 0;
	l = ft_strl(s1)+ 1;
	p = malloc(l);
	if (!p)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc (ft_strl(s1) + ft_strl(s2) + 1 * sizeof (char));
	if (!p)
		return (NULL);
	while (s1[i])
		p[k++] = s1[i++];
	while (s2[j])
		p[k++] = s2[j++];
	p[k] = '\0';
	free (s1);
	s1 = NULL;
	return (p);
}

int	ft_strch(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strl(s);
	while (i <= len)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
