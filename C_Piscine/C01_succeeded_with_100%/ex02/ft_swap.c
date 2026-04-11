/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:38:15 by jshim             #+#    #+#             */
/*   Updated: 2025/10/23 19:22:25 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int main()
{
	int x;
	int y;

	x = 3;
	y = 5;

	printf(" x = %d, y = %d \n", x, y);

	ft_swap(&x,&y);

	printf("--> x = %d, y = %d ", x, y);
	return 0;

}
*/
