/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:37:54 by jshim             #+#    #+#             */
/*   Updated: 2025/10/23 19:24:53 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_sort_int_tab(int *tab, int size)
{
	int	min_idx;
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i >= 0 && i <= size -1)
	{
		min_idx = i;
		j = i + 1;
		while (j <= size -1)
		{
			if (*(tab + min_idx) > *(tab + j))
			{
				min_idx = j;
			}
			j++;
		}
		tmp = *(tab + i);
		*(tab + i) = *(tab + min_idx);
		*(tab + min_idx) = tmp;
		i++;
	}
}

/*
int main (void) 
{
	int a[13] = {3,6,5,4,7,8,9,1,2,8,11,9,0};

	ft_sort_int_tab(a, 13);

	for (int i = 0; i<13; i++)
	{
		printf("%d ", a[i]);
	}
}
*/
