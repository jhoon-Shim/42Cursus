/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:58 by jshim             #+#    #+#             */
/*   Updated: 2025/11/07 11:20:46 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	while (*tmp1 && *tmp1 == *tmp2)
	{
		tmp1 ++;
		tmp2 ++;
	}
	return (*tmp1 - *tmp2);
}
