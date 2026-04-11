/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:04:09 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 20:02:08 by jshim            ###   ########.fr       */
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

// # include <stdio.h>

// int main()
// {
// 	int num;

// 	num = 2147483647;
// 	if (ft_is_prime(num))
// 		printf("%d is a prime\n", num);
// 	else
// 		printf("%d is not a prime\n", num);
// 	return (0);
// }