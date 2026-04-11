/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_views.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:55:18 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 16:58:17 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	parse_input_views(int **col_view, int **row_view, char *tmp, int n)
{
	int	i;
	int	j;
	int	size;

	size = n / 4;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (i < 2 && j < size)
		{
			col_view[i][j] = tmp[i * size + j] - '0';
			j++;
		}
		while (i >= 2 && i < 4 && j < size)
		{
			row_view[i][j] = tmp[i * size + j] - '0';
			j++;
		}
		j = 0;
		i++;
	}
}
