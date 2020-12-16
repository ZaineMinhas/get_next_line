/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:47:32 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/16 13:51:57 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		fd;
	int		size;
	int		i;

	i = -1;
	size = 10;
	if (!(fd = open("test.txt", O_RDONLY)))
		return (-1);
	str = NULL;
	while (++i < size)
	{
		get_next_line(fd, &str);
		printf("%s\n", str);
	}
	close(fd);
	return (0);
}