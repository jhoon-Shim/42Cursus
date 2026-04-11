/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:53 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 11:37:18 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	count;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	count = max - min;
	*range = (int *) malloc (sizeof(int) * count);
	if (!*range)
		return (-1);
	while (i < count)
	{
		(*range)[i] = min + i;
		i++;
	}
	if (i == 0)
		return (-1);
	return (count);
}

// #include <stdio.h>

// int main()
// {
// 	int *arr;
// 	int min = 0;
// 	int max = 7;
// 	int i = 0;
// 	ft_ultimate_range(&arr,min,max);

// 	while(i < max - min)
// 	{
// 		printf("%d ", *(arr+i));
// 		i++;
// 	}
// }