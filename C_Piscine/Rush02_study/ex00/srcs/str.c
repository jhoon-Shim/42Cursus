/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.campus>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/08 15:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (true);
	if (c == '\r' || c == '\v' || c == '\f')
		return (true);
	return (false);
}

bool	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *a, const char *b)
{
	size_t	i;

	i = 0;
	if (a == b)
		return (0);
	while (a && b && a[i] && b[i] && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

char	*ft_strdup(const char *s)
{
	size_t	n;
	size_t	i;
	char	*p;

	n = ft_strlen(s);
	p = (char *)malloc(n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[n] = '\0';
	return (p);
}
