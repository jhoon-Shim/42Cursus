/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:20:22 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 11:37:53 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

// int	main(void)
// {
// 	char	*base_from;
// 	char	*base_to;
// 	char	*nbr;
// 	char	*result;

// 	nbr = "123";
// 	base_from = "01234567";
// 	base_to = "01";
// 	result = ft_convert_base(nbr, base_from, base_to);
// 	printf("Test 1 (Oct '123' -> Bin): %s\n", result);

// 	nbr = "   --+--42";
// 	base_from = "0123456789";
// 	base_to = "0123456789ABCDEF";
// 	result = ft_convert_base(nbr, base_from, base_to);
// 	printf("Test 2 (Dec '42' -> Hex): %s\n", result);

// 	nbr = "  -2A";
// 	base_from = "0123456789ABCDEF";
// 	base_to = "0123456789";
// 	result = ft_convert_base(nbr, base_from, base_to);
// 	printf("Test 3 (Hex '-2A' -> Dec): %s\n", result);

// 	nbr = "0";
// 	base_from = "0123456789";
// 	base_to = "01";
// 	result = ft_convert_base(nbr, base_from, base_to);
// 	printf("Test 4 (Dec '0' -> Bin): %s\n", result);

// 	nbr = "123";
// 	base_from = "01234567";
// 	base_to = "011";
// 	result = ft_convert_base(nbr, base_from, base_to);
// 	printf("Test 5 (Invalid base '011'): %s\n", result);

// 	return (0);
// }