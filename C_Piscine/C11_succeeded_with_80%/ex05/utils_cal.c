/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:11:49 by jshim             #+#    #+#             */
/*   Updated: 2025/11/12 23:49:50 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex05.h"

int	is_valid_op(char *op)
{
	if (op[0] == '\0' || op[1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (op[0] != '+' && op[0] != '-'
		&& op[0] != '*' && op[0] != '/' && op[0] != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int	is_by_zero(char op, int nbr)
{
	if (op == '/' && nbr == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	else if (op == '%' && nbr == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

int	calculate(int nbr1, char op, int nbr2)
{
	int		(*ops[5])(int, int);
	char	op_chars[5];
	int		i;

	ops[0] = &ft_add;
	op_chars[0] = '+';
	ops[1] = &ft_sub;
	op_chars[1] = '-';
	ops[2] = &ft_mul;
	op_chars[2] = '*';
	ops[3] = &ft_div;
	op_chars[3] = '/';
	ops[4] = &ft_mod;
	op_chars[4] = '%';
	i = 0;
	while (i < 5)
	{
		if (op == op_chars[i])
			return (ops[i](nbr1, nbr2));
		i++;
	}
	return (0);
}

int	only_num(char *nbr)
{
	int	i;
	int	sign;
	int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (nbr[i] && (nbr[i] == '+' || nbr[i] == '-'))
	{
		if (nbr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nbr[i] && nbr[i] >= '0' && nbr[i] <= '9')
	{
		nb = nb * 10 + (nbr[i] - '0');
		i++;
	}
	return (nb * sign);
}
