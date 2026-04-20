/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:22:49 by jshim             #+#    #+#             */
/*   Updated: 2026/04/16 20:43:00 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(t_format *fmt, va_list ap)
{
	if (fmt->specifier == 'c')
		return (print_char(va_arg(ap, int), fmt));
	if (fmt->specifier == 's')
		return (print_str(va_arg(ap, char *), fmt));
	if (fmt->specifier == 'p')
		return (print_ptr(va_arg(ap, unsigned long long), fmt));
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
		return (print_int(va_arg(ap, int), fmt));
	if (fmt->specifier == 'u')
		return (print_unsigned(va_arg(ap, unsigned int), fmt));
	if (fmt->specifier == 'x' || fmt->specifier == 'X')
		return (print_hex(va_arg(ap, unsigned int), fmt));
	if (fmt->specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

static void	parse_flags(const char **format, t_format *fmt)
{
	while (**format == '-' || **format == '0' || **format == '#'
		|| **format == ' ' || **format == '+')
	{
		if (**format == '-')
			fmt->minus = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == '#')
			fmt->hash = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else if (**format == '+')
			fmt->plus = 1;
		(*format)++;
	}
}

int	parse_format(const char **format, va_list ap)
{
	t_format	fmt;
	int			count;

	format_init(&fmt);
	(*format)++;
	parse_flags(format, &fmt);
	if (ft_isdigit(**format))
	{
		fmt.width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		fmt.precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	fmt.specifier = **format;
	count = handle_specifier(&fmt, ap);
	if (**format)
		(*format)++;
	return (count);
}

int	ft_printf(const char *sentence, ...)
{
	va_list		ap;
	const char	*ptr;
	int			len;
	int			tmp;

	len = 0;
	ptr = sentence;
	va_start(ap, sentence);
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) == '\0')
			break ;
		if (*ptr == '%')
			tmp = parse_format(&ptr, ap);
		else
			tmp = write(1, ptr++, 1);
		if (tmp == -1)
		{
			va_end(ap);
			return (-1);
		}
		len += tmp;
	}
	va_end(ap);
	return (len);
}
