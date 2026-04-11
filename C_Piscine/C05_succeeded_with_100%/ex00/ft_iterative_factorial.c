/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:12:46 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 20:02:19 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	num = nb;
	while (nb >= 2)
		num *= (nb-- - 1);
	return (num);
}

// #include <stdio.h>

// int main(void)
// {
// 	int num;

// 	num = 10;
// 	printf("%d! = %d\n",num,ft_iterative_factorial(num));
// }