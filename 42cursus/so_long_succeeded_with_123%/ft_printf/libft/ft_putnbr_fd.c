/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:01:11 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:58:30 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, "8", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		str = '0' + n % 10;
	}
	else
		str = '0' + n;
	write(fd, &str, 1);
}

// #include <stdio.h>

// void	ft_putnbr_fd(int n, int fd);

// int main(void)
// {
// 	printf("[NORMAL]   expect: -42\nactual: ");
// 	fflush(stdout);
// 	ft_putnbr_fd(-42, 1);
// 	printf("\n");

// 	printf("[EDGE]     expect: -2147483648\nactual: ");
// 	fflush(stdout);
// 	ft_putnbr_fd(-2147483648, 1);
// 	printf("\n");

// 	printf("[OVERFLOW] expect: (nothing)\nactual: ");
// 	fflush(stdout);

// 	printf("SKIP\n");

// 	return 0;
// }
