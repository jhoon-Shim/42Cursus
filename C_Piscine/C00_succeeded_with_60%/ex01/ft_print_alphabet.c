/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:50:52 by jshim             #+#    #+#             */
/*   Updated: 2025/10/22 22:54:32 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	alphabet;
	int		i;

	alphabet = 'a';
	i = 0;
	while (i < 26)
	{
		write(1, &alphabet, 1);
		alphabet++;
		i++;
	}
}

/* int	main()
{
	ft_print_alphabet();
	return 0;
}
*/
