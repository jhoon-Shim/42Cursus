/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:56:04 by jshim             #+#    #+#             */
/*   Updated: 2026/04/16 20:55:32 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_format *fmt)
{
	int	count;

	count = 0;
	if (fmt->minus)
	{
		count += write(1, &c, 1);
		count += put_padding(fmt->width - 1, ' ');
	}
	else
	{
		count += put_padding(fmt->width - 1, ' ');
		count += write(1, &c, 1);
	}
	return (count);
}

int	print_str(char *str, t_format *fmt)
{
	int	count;
	int	len;

	if (!str)
	{
		if (fmt->precision >= 0 && fmt->precision < 6)
			str = "";
		else
			str = "(null)";
	}
	len = ft_strlen(str);
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	count = 0;
	if (fmt->minus)
	{
		count += write(1, str, len);
		count += put_padding(fmt->width - len, ' ');
	}
	else
	{
		count += put_padding(fmt->width - len, ' ');
		count += write(1, str, len);
	}
	return (count);
}
