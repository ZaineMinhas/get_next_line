/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:47:32 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/20 14:35:06 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		fd;
	int		size;
	int		i;

	i = -1;
	size = 14;
	if (!(fd = open("test.txt", O_RDONLY)))
		return (-1);
	str = NULL;
	while (++i < size)
	{
		get_next_line(fd, &str);
		printf("%s - %d\n", str, i);
	}
	close(fd);
	return (0);
}
