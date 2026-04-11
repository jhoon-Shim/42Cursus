/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:54:46 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 16:57:10 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**allocate_view(int rows, int cols)
{
	int	**view;
	int	i;
	int	j;

	view = (int **)malloc(rows * 8);
	if (view == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		view[i] = (int *)malloc(cols * 4);
		j = 0;
		while (j < cols)
		{
			view[i][j] = 0;
			j++;
		}
		i++;
	}
	return (view);
}
