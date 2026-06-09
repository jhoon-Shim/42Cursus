/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:13:04 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 06:22:03 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	if (size == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (slen + size);
	i = 0;
	while (src[i] && dlen + i + 1 < size)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

// #include <stdio.h>

// /* 단독 실행용 ft_strlen 더미 */
// unsigned int	ft_strlen(const char *s)
// {
// 	unsigned int i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int main(void)
// {
// 	char d1[10] = "hi";
// 	char d2[3] = "hi";
// 	unsigned int r;

// 	printf("[NORMAL]   "); fflush(stdout);
// 	r = ft_strlcat(d1, "42", 10);
// 	printf("dest='%s' ret=%u\n", d1, r); /* 기대: hi42, ret=4 */

// 	printf("[EDGE]     "); fflush(stdout);
// 	char e[3] = "hi";
// 	r = ft_strlcat(e, "X", 3);
// 	printf("[EDGE]     dest='%s' ret=%u\n", e, r); /* 기대: dest='hi' ret=3 */

// 	printf("[OVERFLOW] "); fflush(stdout);
// 	/* size==0이면 현재 구현은 d2[dest_len]에 '\0' 쓰려다 OOB 가능 */
// 	r = ft_strlcat(d2, "Z", 0);
// 	printf("ret=%u (should not write)\n", r);

// 	return (0);
// }
