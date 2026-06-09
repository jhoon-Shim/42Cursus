/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:48 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:28:33 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c <= 'Z' && c >= 'A'))
		return (1);
	return (0);
}

// // main.c
// #include <stdio.h>

// int ft_isalpha(int c);

// int main(void)
// {
//     printf("[NORMAL]   %d\n", ft_isalpha('z'));
//     printf("[EDGE]     %d\n", ft_isalpha('9'));
//     printf("[OVERFLOW] %d\n", ft_isalpha(300));
//     return 0;
// }
