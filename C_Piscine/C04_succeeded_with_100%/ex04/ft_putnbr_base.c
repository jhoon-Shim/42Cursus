/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:00:00 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/30 01:46:48 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		base_len;

	if (!check_base(base))
		return ;
	num = nbr;
	base_len = ft_strlen(base);
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= base_len)
		ft_putnbr_base(num / base_len, base);
	ft_putchar(base[num % base_len]);
}

// int main(void)
// {
// 	ft_putnbr_base(42, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "poneyvif");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "00"); 
// 	write(1, "\n", 1);
// 	return (0);
// }
