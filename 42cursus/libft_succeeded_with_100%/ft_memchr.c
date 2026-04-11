/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:57 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 21:53:24 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;

	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	while (n--)
	{
		if (*tmp_s == tmp_c)
			return ((void *)tmp_s);
		tmp_s ++;
	}
	return (NULL);
}
