/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:30:42 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/19 16:31:14 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_check_error(int fd, char **line);
int		ft_backslash_checker(char *str);
char	*ft_get_line(char *str);
int		ft_return(char **buff, int i, char **line, char **str_save);
int		get_next_line(int fd, char **line);

size_t	ft_strlen_protect(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_gnljoin(char const *s1, char const *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr_dup_remix(const char *s, int c);

#endif
