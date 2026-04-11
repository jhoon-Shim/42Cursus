/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:53:39 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 11:38:56 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	count;
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	count = max - min;
	arr = (int *) malloc (sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// #include <stdio.h>

// int main ()
// {

// 	int * arr;
// 	arr = ft_range(-1,5);
// 	int i = 0;
// 	while(i < 6)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}	
// }