/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:08:30 by jshim             #+#    #+#             */
/*   Updated: 2025/10/26 00:15:13 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	int				idx;
	int				p;
	int				q;
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	hex = "0123456789abcdef";
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] <= 31 || str[idx] >= 127)
		{
			p = tmp[idx] / 16;
			q = tmp[idx] % 16;
			write(1, "\\", 1);
			write(1, hex + p, 1);
			write(1, hex + q, 1);
		}
		else
		{
			write(1, str + idx, 1);
		}
		idx ++;
	}
}

// int main(void) 
// {
// 	char arr[] = "Hello\nHow are you?";
// 	char *str;

// 	str = arr;

// 	ft_putstr_non_printable(str);
// 	return 0;
// }
