/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:02:13 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 05:23:44 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	join = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i ++;
	}
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		join[i] = s2[i - ft_strlen(s1)];
		i ++;
	}
	join[i] = '\0';
	return (join);
}

// #include <stdio.h>

// /* 테스트용 ft_strlen (단독 실행용) */
// unsigned int	ft_strlen(const char *s)
// {
// 	unsigned int i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2);

// int main(void)
// {
// 	char *r;

// 	printf("[NORMAL]   "); fflush(stdout);
// 	r = ft_strjoin("hello", "42");
// 	printf("%s\n", r);
// 	free(r);

// 	printf("[EDGE]     "); fflush(stdout);
// 	r = ft_strjoin("", "abc");
// 	printf("%s\n", r);
// 	free(r);

// 	printf("[OVERFLOW] "); fflush(stdout);
// 	/* r = ft_strjoin(NULL, "x"); */ /* NULL 가드 없으면 크래시 */
// 	printf("SKIP (add NULL guard)\n");

// 	return (0);
// }
