/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:13:00 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 12:08:55 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	if (!dest && !src)
		return (dest);
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dest;
	i = 0;
	if (tmp1 < tmp2)
	{
		while (n--)
			tmp2[n] = tmp1[n];
	}
	else
	{
		while (i < n)
		{
			tmp2[i] = tmp1[i];
			i++;
		}
	}
	return (dest);
}
