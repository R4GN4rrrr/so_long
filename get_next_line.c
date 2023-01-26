/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 04:23:52 by ymenyoub          #+#    #+#             */
/*   Updated: 2023/01/23 18:08:07 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

char	*ft_add_join(int fd, char *saved)
{
	int		nbyte;
	char	*buff;

	nbyte = 1;
	if (!saved)
		saved = ft_strd("");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (nbyte && !ft_strch(saved))
	{
		nbyte = read(fd, buff, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(saved);
			free(buff);
			saved = NULL;
			return (NULL);
		}
		buff[nbyte] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free (buff);
	return (saved);
}

char	*ft_line(char *string)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	str = malloc((i + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		str[j++] = string[i++];
	if (string[i] == '\n')
		str[j++] = string[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_rest(char *save)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	s = malloc((ft_strl(save) - i) * sizeof(char));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	if (save[i] == '\n')
		s[j++] = save[i];
	s[j] = '\0';
	free (save);
	save = NULL;
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_add_join(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_rest(save);
	return (line);
}
