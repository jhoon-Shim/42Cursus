/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:42:08 by jshim             #+#    #+#             */
/*   Updated: 2025/11/12 23:49:05 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex05.h"

int	main(int argc, char *argv[])
{
	char	op;
	int		nbr1;
	int		nbr2;
	int		result;

	if (argc != 4)
		return (0);
	if (!is_valid_op(argv[2]))
		return (0);
	op = argv[2][0];
	nbr1 = only_num(argv[1]);
	nbr2 = only_num(argv[3]);
	if (is_by_zero(op, nbr2))
		return (0);
	result = calculate(nbr1, op, nbr2);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
