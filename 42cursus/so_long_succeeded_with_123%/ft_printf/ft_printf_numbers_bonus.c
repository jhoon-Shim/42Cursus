/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:56:16 by jshim             #+#    #+#             */
/*   Updated: 2026/04/16 20:41:12 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_uitoa(unsigned int n)
{
	char	buf[11];
	int		i;

	i = 10;
	buf[i] = '\0';
	if (n == 0)
		buf[--i] = '0';
	while (n > 0)
	{
		buf[--i] = '0' + (n % 10);
		n /= 10;
	}
	return (ft_strdup(&buf[i]));
}

static int	put_sign(t_format *fmt, int is_neg)
{
	if (is_neg)
		return (write(1, "-", 1));
	if (fmt->plus)
		return (write(1, "+", 1));
	if (fmt->space)
		return (write(1, " ", 1));
	return (0);
}

static int	put_num(char *s, t_format *fmt, int len, int is_neg)
{
	int	count;
	int	p_len;
	int	sign_len;

	count = 0;
	p_len = len;
	if (fmt->precision > len)
		p_len = fmt->precision;
	sign_len = 0;
	if (is_neg || fmt->plus || fmt->space)
		sign_len = 1;
	if (!fmt->minus && !(fmt->zero && fmt->precision < 0))
		count += put_padding(fmt->width - p_len - sign_len, ' ');
	count += put_sign(fmt, is_neg);
	if (!fmt->minus && (fmt->zero && fmt->precision < 0))
		count += put_padding(fmt->width - p_len - sign_len, '0');
	count += put_padding(fmt->precision - len, '0');
	count += write(1, s, len);
	if (fmt->minus)
		count += put_padding(fmt->width - p_len - sign_len, ' ');
	return (count);
}

int	print_int(int n, t_format *fmt)
{
	char			*s;
	int				count;
	int				len;
	int				is_neg;
	unsigned int	num;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	if (n == 0 && fmt->precision == 0)
		return (put_padding(fmt->width, ' '));
	s = ft_uitoa(num);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	count = put_num(s, fmt, len, is_neg);
	free(s);
	return (count);
}

int	print_unsigned(unsigned int n, t_format *fmt)
{
	char	*s;
	int		count;
	int		len;

	if (n == 0 && fmt->precision == 0)
		return (put_padding(fmt->width, ' '));
	s = ft_uitoa(n);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	fmt->plus = 0;
	fmt->space = 0;
	count = put_num(s, fmt, len, 0);
	free(s);
	return (count);
}
