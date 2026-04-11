/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:15:54 by jshim             #+#    #+#             */
/*   Updated: 2025/10/30 01:46:25 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	ch;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
	}
	ch = '0';
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ch += nb % 10;
	write(1, &ch, 1);
	return ;
}

// int	main(void)
// {
// 	int	nb;

// 	nb = 212345;
// 	ft_putnbr(nb);
// 	return (0);
// }
