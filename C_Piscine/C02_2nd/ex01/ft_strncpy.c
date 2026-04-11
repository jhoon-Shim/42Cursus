/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:09:10 by jshim             #+#    #+#             */
/*   Updated: 2025/10/24 22:38:36 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h> 
#include <string.h>
*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx ++;
	}
	while (idx < n)
	{
		dest[idx] = '\0';
		idx ++;
	}
	return (dest);
}

/*
int main(void) 
{
	char source[] = "All I want for christmas is you ~asjkhdjkashdjk";
	char destination[100];
	char *test;
	test = "abc";
	strncpy(destination,source,sizeof(source)-3);
	printf("%s\n%s",source,destination);
	return 0;
}
*/
