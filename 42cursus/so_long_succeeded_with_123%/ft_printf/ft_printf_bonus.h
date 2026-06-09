/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:57:33 by jshim             #+#    #+#             */
/*   Updated: 2026/04/16 20:43:40 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_format
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

void	format_init(t_format *fmt);
int		ft_printf(const char *sentence, ...);
int		parse_format(const char **format, va_list ap);
int		put_padding(int len, char c);
int		print_int(int n, t_format *fmt);
int		print_unsigned(unsigned int n, t_format *fmt);
int		print_hex(unsigned int n, t_format *fmt);
int		print_ptr(unsigned long long ptr, t_format *fmt);
int		print_str(char *str, t_format *fmt);
int		print_char(char c, t_format *fmt);

#endif
