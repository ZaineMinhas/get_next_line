/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:13:57 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/20 12:59:01 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen_remix(const char *s)
{
	size_t i;

	 if (!s)
	 	return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_backslash_checker(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin_remix(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;

	size = ft_strlen_remix(s1) + ft_strlen_remix(s2) + 1;
	if (!(dest = (char *)ft_calloc(sizeof(char), size)))
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen_remix(s1));
	ft_memcpy(dest + ft_strlen_remix(s1), s2, ft_strlen_remix(s2));
	return (dest);
}

char	*ft_strdup_remix(char *str)
{
	size_t	size;
	char	*dest;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] != '\n')
		size++;
	if (!(dest = ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	size = -1;
	while (str[++size] != '\n')
		dest[size] = str[size];
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char *str_save;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (ft_backslash_checker(str_save))
	{
		*line = ft_strdup_remix(str_save);
		str_save = ft_strdup(ft_strchr(str_save, '\n') + 1);
		return (1);
	}
	while ((i = (int)read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = 0;
		str_save = ft_strjoin_remix(str_save, buf);
		if (ft_backslash_checker(str_save))
		{
		*line = ft_strdup_remix(str_save);
		str_save = ft_strdup(ft_strchr(str_save, '\n') + 1);
		return (1);
		}
	}
	return (0);
}