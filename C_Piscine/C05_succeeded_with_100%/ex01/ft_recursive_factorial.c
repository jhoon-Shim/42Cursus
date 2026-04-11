/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:01:42 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 20:02:17 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb >= 2)
		nb = nb * ft_recursive_factorial(nb - 1);
	return (nb);
}

// #include <stdio.h>

// int main(void)
// {
// 	int num;

// 	num = 10;
// 	printf("%d! = %d\n",num,ft_recursive_factorial(num));
// }