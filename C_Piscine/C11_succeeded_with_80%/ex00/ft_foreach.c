/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:41:44 by jshim             #+#    #+#             */
/*   Updated: 2025/11/12 17:02:18 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// #include <unistd.h>

// void	ft_putchar(int ch)
// {
// 	char a;

// 	a = ch + '0'; 
// 	write(1, &a, 1);
// 	write(1, "\n", 1);
// }

// int main()
// {
// 	int	tab[100] = {0, 1, 2, 3, 4, 5}; 
// 	ft_foreach(tab, 6, &ft_putchar);
// }