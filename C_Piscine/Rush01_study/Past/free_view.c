/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:54:50 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 16:57:54 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_view(int **view, int rows)
{
	int	i;

	if (view == NULL)
		return ;
	i = 0;
	while (i < rows)
	{
		free(view[i]);
		i++;
	}
	free(view);
}
