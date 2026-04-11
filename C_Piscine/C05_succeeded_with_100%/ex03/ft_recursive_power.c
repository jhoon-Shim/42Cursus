/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:26:07 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 20:02:14 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power >= 2)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}

// #include <stdio.h>

// int main (void)
// {
// 	int nb;
// 	int pow;

// 	nb = -10;
// 	pow = 3;
// 	printf("(%d)^%d = %d",nb,pow,ft_recursive_power(nb,pow));
// }