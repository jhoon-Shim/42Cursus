/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:13:05 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 13:56:01 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (idx < size -1 && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx ++;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}
