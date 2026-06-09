/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:56:32 by jshim             #+#    #+#             */
/*   Updated: 2026/04/16 20:42:43 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	put_hex(unsigned long long n, char spec)
{
	char	*base;

	if (spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, spec);
	write(1, &base[n % 16], 1);
}

static int	put_hex_prefix(int prefix, char spec)
{
	if (prefix && spec == 'x')
		return (write(1, "0x", 2));
	else if (prefix)
		return (write(1, "0X", 2));
	return (0);
}

int	print_hex(unsigned int n, t_format *fmt)
{
	int	count;
	int	len;
	int	prfx;
	int	p_len;

	if (n == 0 && fmt->precision == 0)
		return (put_padding(fmt->width, ' '));
	len = get_hex_len(n);
	prfx = 0;
	if (fmt->hash && n != 0)
		prfx = 2;
	p_len = len;
	if (fmt->precision > len)
		p_len = fmt->precision;
	count = 0;
	if (!fmt->minus && !(fmt->zero && fmt->precision < 0))
		count += put_padding(fmt->width - p_len - prfx, ' ');
	count += put_hex_prefix(prfx, fmt->specifier);
	if (!fmt->minus && (fmt->zero && fmt->precision < 0))
		count += put_padding(fmt->width - p_len - prfx, '0');
	count += put_padding(fmt->precision - len, '0');
	put_hex(n, fmt->specifier);
	if (fmt->minus)
		return (count + len + put_padding(fmt->width - p_len - prfx, ' '));
	return (count + len);
}

int	print_ptr(unsigned long long ptr, t_format *fmt)
{
	int	count;
	int	len;

	if (!ptr)
		return (print_str("(nil)", fmt));
	len = get_hex_len(ptr) + 2;
	count = 0;
	if (!fmt->minus)
		count += put_padding(fmt->width - len, ' ');
	write(1, "0x", 2);
	put_hex(ptr, 'x');
	count += len;
	if (fmt->minus)
		count += put_padding(fmt->width - len, ' ');
	return (count);
}
