/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:13:57 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/20 15:30:44 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_protected(const char *s)
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

	size = ft_strlen_protected(s1) + ft_strlen_protected(s2) + 1;
	if (!(dest = (char *)ft_calloc(sizeof(char), size)))
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen_protected(s1));
	ft_memcpy(dest + ft_strlen_protected(s1), s2, ft_strlen_protected(s2));
	return (dest);
}

char	*ft_get_line(char *str)
{
	size_t	size;
	char	*dest;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	if (!(dest = (char *)ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	size = -1;
	while (str[++size] != '\n')
		dest[size] = str[size];
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char *str_save[OPEN_MAX];
	char		*buf;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || !line ||\
	!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	i = 1;
	while (!ft_backslash_checker(str_save[fd]) && i)
	{
		if ((i = (int)read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[i] = 0;
		str_save[fd] = ft_strjoin_remix(str_save[fd], buf);
	}
	*line = ft_get_line(str_save[fd]);
	str_save[fd] = ft_strdup(ft_strchr(str_save[fd], '\n') + 1);
	if (i)
		return (1);
	return (0);
}
