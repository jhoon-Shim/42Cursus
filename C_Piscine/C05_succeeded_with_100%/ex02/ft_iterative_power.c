/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:09:21 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 20:02:15 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	if (power < 0)
		return (0);
	if (power == 0)
	{
		return (1);
	}
	num = 1;
	while (power > 0)
	{
		num *= nb;
		power --;
	}
	return (num);
}

// #include <stdio.h>

// int main(void)
// {
// 	int nb;
// 	int power;

// 	nb = -9;
// 	power = 3;
// 	printf("(%d)^%d = %d",nb,power,ft_iterative_power(nb,power));
// }