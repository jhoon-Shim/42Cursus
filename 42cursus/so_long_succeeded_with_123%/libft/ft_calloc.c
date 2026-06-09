/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:50:35 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:40:02 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// #include <stdio.h>

// int main(void)
// {
//     void *a = ft_calloc((size_t)-1, 2);
//     void *b = ft_calloc(10, 4);
//     void *c = ft_calloc(0, 100);

//     printf("[OVERFLOW] %p\n", a);
//     printf("[NORMAL]   %p\n", b);
//     printf("[EDGE]     %p\n", c);

//     free(b);
//     free(c);
//     return 0;
// }