/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:33:17 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 20:02:24 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
	{
		return (ft_fibonacci(index -1) + ft_fibonacci(index - 2));
	}
}

// #include <stdio.h>

// int main (void)
// {
// 	int idx;

// 	idx = 10;
// 	printf("%d 's fibonacci val = %d", idx, ft_fibonacci(idx));
// }