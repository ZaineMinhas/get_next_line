/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:20:32 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/23 15:23:31 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen_protect(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr_dup_remix(const char *s, int c);
char		*ft_strdup(char *s1);
char		*ft_get_line(char *str);
char		*ft_strjoin_remix(char const *s1, char const *s2);

#endif