/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:13:57 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/15 18:56:13 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	i;
	char	*dest;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] && !ft_strchr(str, '\n'))
		size++;
	if (!(dest = ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	i = -1;
	while (dest[++i])
		dest[i] = str[i];
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char *str_save;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	str_save = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0 && !ft_strchr(buf, '\n'))
	{
		str_save = ft_strjoin_remix(str_save, buf);
		if (ft_strchr(str_save, '\n'))
		{
			*line = ft_strdup_remix(str_save);
			str_save = ft_strdup(ft_strchr(buf, '\n') + 1);
			return (1);
		}
	}
	return (0);
}
