/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:47:32 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/20 18:18:49 by zminhas          ###   ########.fr       */
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
	size = 23;
	if (!(fd = open("texte.txt", O_RDONLY)))
		return (-1);
	str = NULL;
	while (++i < size)
	{
		get_next_line(fd, &str);
		printf("%d - %s", i, str);
	}
	close(fd);
	return (0);
}
