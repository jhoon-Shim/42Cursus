/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:45 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:28:14 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// // main.c
// #include <stdio.h>

// int ft_isalnum(int c);

// int main(void)
// {
//     printf("[NORMAL]   %d\n", ft_isalnum('A'));
//     printf("[EDGE]     %d\n", ft_isalnum('#'));
//     printf("[OVERFLOW] %d\n", ft_isalnum(256));
//     return 0;
// }