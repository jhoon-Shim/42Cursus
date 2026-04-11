/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:18:16 by jshim             #+#    #+#             */
/*   Updated: 2025/10/23 19:22:21 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*(str + count) != '\0')
	{
		write(1, str + count, 1);
		count++;
	}
}

/*
int	main(void)
{
	char	*ch;

	ch = "abracatabra";
	ft_putstr(ch);
	return (0);
}
*/