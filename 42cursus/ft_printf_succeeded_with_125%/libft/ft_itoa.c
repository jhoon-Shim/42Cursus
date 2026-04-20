/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:42:35 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:31:02 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

// // main.c
// #include <stdio.h>
// #include <stdlib.h>

// char *ft_itoa(int n);

// int main(void)
// {
//     char *a = ft_itoa(-2147483648);
//     char *b = ft_itoa(42);
//     char *c = ft_itoa(0);

//     printf("[OVERFLOW] %s\n", a);
//     printf("[NORMAL]   %s\n", b);
//     printf("[EDGE]     %s\n", c);

//     free(a);
//     free(b);
//     free(c);
//     return 0;
// }
