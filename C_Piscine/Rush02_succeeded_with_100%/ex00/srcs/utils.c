/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namykim <namykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:57:12 by namykim           #+#    #+#             */
/*   Updated: 2025/11/09 22:57:14 by namykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_str(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	put_err(const char *s)
{
	if (s)
		write(2, s, ft_strlen(s));
}

void	free_ptr(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}
