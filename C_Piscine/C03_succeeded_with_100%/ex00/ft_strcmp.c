/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:27:35 by jshim             #+#    #+#             */
/*   Updated: 2025/10/27 11:38:47 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

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

// int main (void)
// {
// 	char *s1 = "hgcghvhgvg";
// 	char *s2 = "hgcgzvha";

// 	printf("%d\n", ft_strcmp(s1,s2));
// }