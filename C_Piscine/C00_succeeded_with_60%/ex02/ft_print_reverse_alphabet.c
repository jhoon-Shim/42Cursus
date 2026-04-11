/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:25:22 by jshim             #+#    #+#             */
/*   Updated: 2025/10/22 23:33:56 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alphabet;
	int		i;

	alphabet = 'z';
	i = 0;
	while (i < 26)
	{
		write(1, &alphabet, 1);
		alphabet--;
		i++;
	}
}

/* int	main()
{
	ft_print_reverse_alphabet();
	return 0;
}
*/	
