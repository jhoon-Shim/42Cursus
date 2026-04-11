/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 00:16:28 by jshim             #+#    #+#             */
/*   Updated: 2025/10/26 00:48:53 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
// {

// 	return (addr);
// }

// int main(void)
// {
// 	char	*a;
// 	char	*b;
// 	char	*c;
// 	char	*d;
// 	char	*e;
// 	char	*f;

// 	a = "Bonjour les amin";
// 	b = "ches...c. est fo";
// 	c = "u.tout.ce qu on ";
// 	d = "peut faire avec.";
// 	e = "..print_memory..";
// 	f = "..lol.lol. .";

// 	ft_print_memory((void *)a, 16);
// 	ft_print_memory(b, 16);
// 	ft_print_memory(c, 16);
// 	ft_print_memory(d, 0);
// 	ft_print_memory(e, 7);
// 	ft_print_memory(f, 5);
// }