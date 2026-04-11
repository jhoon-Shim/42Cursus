/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:36:44 by jshim             #+#    #+#             */
/*   Updated: 2025/10/26 11:07:37 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
#include <stdio.h>
*/

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

/*
int main(void)
{
	char A[100];
	char B[11];
	int i;

	for(i =0; i<10; i++)
	{
		*(B+i) = 'A'+i;
	}
	B[i] = '\0';
	ft_strcpy(A,B);
	printf("A: %s, B: %s", A,B);
	return (0);
}
*/