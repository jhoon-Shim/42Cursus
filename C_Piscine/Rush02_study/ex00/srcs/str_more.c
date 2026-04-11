/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.campus>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/08 15:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*p;

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

char	*ft_strtrim(const char *s)
{
	size_t	l;
	size_t	r;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (n == 0)
		return (ft_strdup(""));
	l = 0;
	r = n - 1;
	while (l < n && ft_is_space(s[l]))
		l++;
	while (r > l && ft_is_space(s[r]))
		r--;
	if (l > r)
		return (ft_strdup(""));
	return (ft_strndup(s + l, r - l + 1));
}
