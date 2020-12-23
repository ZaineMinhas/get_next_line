/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:20:26 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/23 15:24:37 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	char *s2;

	s2 = (char *)s;
	while (n-- > 0)
		s2[n] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*dest;

	if (!(dest = malloc(sizeof(void) * (size * count))))
		return (NULL);
	ft_bzero(dest, (count * size));
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src2;
	char		*dest2;

	if (!src && !dest)
		return (dest);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	while (n-- > 0)
		dest2[n] = src2[n];
	return ((void *)dest2);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	if (!(dest = (char *)ft_calloc(sizeof(char), (ft_strlen_protect(s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	return (dest);
}

char	*ft_strchr_dup_remix(const char *s, int c)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
		{
			dest = ft_strdup((char *)(s + i + 1));
			free((void *)s);
			return (dest);
		}
	free((void *)s);
	return (NULL);
}
