/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:13:17 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 20:02:07 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	i = 1;
	while (nb + i <= 2147483647)
	{
		if (ft_is_prime(nb + i))
			return (nb + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	int num;

// 	num = 252;
// 	printf("the next prime of %d is %d", num, ft_find_next_prime(num));
// 	return (0);
// }