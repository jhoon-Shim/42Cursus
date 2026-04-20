/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:55:50 by jshim             #+#    #+#             */
/*   Updated: 2026/04/16 20:07:14 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_init(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->hash = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = 0;
}

int	put_padding(int len, char c)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += write(1, &c, 1);
		len--;
	}
	return (count);
}
