/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:53 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:30:27 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// // main.c
// #include <stdio.h>

// int ft_isprint(int c);

// int main(void)
// {
//     printf("[NORMAL]   %d\n", ft_isprint('A'));     // printable
//     printf("[EDGE]     %d\n", ft_isprint(31));      // non-printable
//     printf("[OVERFLOW] %d\n", ft_isprint(200));     // out of ASCII range
//     return 0;
// }
