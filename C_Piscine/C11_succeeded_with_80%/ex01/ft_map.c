/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:03:11 by jshim             #+#    #+#             */
/*   Updated: 2025/11/12 17:15:43 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * length);
	if (!arr)
		return (NULL);
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}

// #include <stdio.h>

// int square(int x)
// {
//     return x * x;
// }

// int main(void)
// {
//     int tab[] = {1, 2, 3, 4, 5};
//     int length = 5;
//     int *res = ft_map(tab, length, &square);

//     for (int i = 0; i < length; i++)
//         printf("%d ", res[i]);
//     printf("\n");

//     free(res);
//     return 0;
// }
