/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.campus>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/08 15:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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
