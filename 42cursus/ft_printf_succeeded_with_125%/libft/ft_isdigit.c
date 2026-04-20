/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:52 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:30:03 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// // main.c
// #include <stdio.h>

// int ft_isdigit(int c);

// int main(void)
// {
//     printf("[NORMAL]   %d\n", ft_isdigit('5'));
//     printf("[EDGE]     %d\n", ft_isdigit('a'));
//     printf("[OVERFLOW] %d\n", ft_isdigit(500));
//     return 0;
// }
