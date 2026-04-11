/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:12:10 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 21:30:46 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

#include <stdio.h>

int main(void)
{
	t_point	point;
	set_point(&point);
	printf("%d %d\n", point.x, point.y);
	return (0);
}