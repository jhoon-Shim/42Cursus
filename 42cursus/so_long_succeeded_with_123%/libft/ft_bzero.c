/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:43 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:29:32 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n--)
		*(temp++) = 0;
}

// #include <stdio.h>

// int main(void)
// {
//     unsigned char buf[5] = {1, 2, 3, 4, 5};

//     ft_bzero(buf, 5);
//     printf("[NORMAL]   %d %d %d %d %d\n", 
// buf[0], buf[1], buf[2], buf[3], buf[4]);

//     ft_bzero(buf, 0);
//     printf("[EDGE]     %d %d %d %d %d\n", 
// buf[0], buf[1], buf[2], buf[3], buf[4]);

//     ft_bzero(NULL, 0);
//     printf("[OVERFLOW] NULL + 0 OK\n");

//     return 0;
// }