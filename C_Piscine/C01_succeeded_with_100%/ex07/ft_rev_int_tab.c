/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:56:20 by jshim             #+#    #+#             */
/*   Updated: 2025/10/23 18:37:21 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	count;

	count = size / 2;
	while (count > 0)
	{
		temp = *(tab + count - 1);
		*(tab + count -1) = *(tab + size - count);
		*(tab + size - count) = temp;
		count --;
	}
}

/*
int	main() 
{
	int table[11] = {0,1,2,3,4,5,6,7,8,9,10};
	
	for (int i = 0; i<11; i++)
	{
		printf("%d ", table[i]);
	}

	printf("\n");

	ft_rev_int_tab(table, 11);
	
	for (int j = 0; j<11; j++)
	{
		printf("%d ", table[j]);
	}
}
*/