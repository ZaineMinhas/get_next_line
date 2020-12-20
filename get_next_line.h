/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:10:16 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/20 14:35:55 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen_remix(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strdup_remix(char *str);
char		*ft_strjoin_remix(char const *s1, char const *s2);

#endif
