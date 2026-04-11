/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:05:24 by jshim             #+#    #+#             */
/*   Updated: 2025/11/13 01:31:35 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	dir1;
	int	dir2;
	int	k;

	i = 0;
	while (i < length - 1)
	{
		dir1 = f(tab[i], tab[i + 1]);
		if (dir1 != 0)
		{
			k = i + 1;
			while (k < length - 1)
			{
				dir2 = f(tab[k], tab[k + 1]);
				if ((dir1 < 0 && dir2 > 0)
					|| (dir1 > 0 && dir2 < 0))
					return (0);
				k++;
			}
		}
		i++;
	}
	return (1);
}

#include <stdio.h>

int cmp(int a, int b) { return (a - b); }

int main(void)
{
	int arr1[] = {1, 2, 2, 1};
	int arr2[] = {1, 1, 2, 1};
	int arr3[] = {1, 3, 2, 4};

	printf("%d\n", ft_is_sort(arr1, 4, cmp)); // 1
	printf("%d\n", ft_is_sort(arr2, 4, cmp)); // 1
	printf("%d\n", ft_is_sort(arr3, 4, cmp)); // 0
}
