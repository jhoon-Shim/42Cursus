/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:12:50 by jshim             #+#    #+#             */
/*   Updated: 2025/10/23 01:04:14 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	num;
	int		i;

	i = 0;
	num = '0';
	while (i < 10)
	{
		write(1, &num, 1);
		num ++;
		i ++;
	}
}

/* int	main()
{
	ft_print_numbers();
	return 0;
}
*/
