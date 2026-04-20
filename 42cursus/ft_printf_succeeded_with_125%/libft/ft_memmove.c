/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:13:00 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 21:53:15 by jshim            ###   ########.fr       */
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

// #include <stdio.h>

// /* 프로토타입 */
// void *ft_memmove(void *dest, const void *src, size_t n);

// int main(void)
// {
//     char a1[] = "abcdef";
//     char a2[] = "abcdef";

//     /* OVERFLOW */
//     ft_memmove(NULL, NULL, 0);
//     printf("[OVERFLOW] NULL + 0 OK\n");

//     /* NORMAL */
//     ft_memmove(a1 + 3, "XYZ", 3);
//     printf("[NORMAL]   %s\n", a1);

//     /* EDGE (overlap) */
//     ft_memmove(a2 + 1, a2, 5);
//     printf("[EDGE]     %s\n", a2); /* 기대: aabcde */

//     return 0;
// }
