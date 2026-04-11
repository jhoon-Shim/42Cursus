/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:40:42 by jshim             #+#    #+#             */
/*   Updated: 2025/10/23 01:05:17 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	signal;

	if (n < 0)
	{
		signal = 'N';
		write(1, &signal, 1);
	}
	else
	{
		signal = 'P';
		write(1, &signal, 1);
	}
}

/* int	main(){

	ft_is_negative(0);
	ft_is_negative(-1);
	ft_is_negative(-2);
	ft_is_negative(1);
	ft_is_negative(2);

	return 0;
}
*/
