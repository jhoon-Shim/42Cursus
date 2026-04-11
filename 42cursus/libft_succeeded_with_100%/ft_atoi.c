/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:31 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:38:42 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	a;
	int		sign;

	a = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		a = a * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(a * sign));
}

// #include <stdio.h>

// int main(void)
// {
//     printf("[OVERFLOW] %d\n", ft_atoi("2147483648"));
//     printf("[NORMAL]   %d\n", ft_atoi("   -42"));
//     printf("[EDGE]     %d\n", ft_atoi("+-123"));
//     return 0;
// }
