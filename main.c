/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:47:32 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/15 18:34:41 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	add(char *str)
{
	static char	*a;

	if (!a)
		printf("First occurence\n");
	else
		printf("Previous occurence was %s\n", a);
	a = str;
}

int		main(void)
{
	add("Boojour");
	add("Comment");
	add("ca va");
	return (0);
}
