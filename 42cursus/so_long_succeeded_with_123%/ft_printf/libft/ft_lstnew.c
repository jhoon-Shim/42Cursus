/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:12:46 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:44:55 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *) malloc (sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp -> content = content;
	tmp -> next = NULL;
	return (tmp);
}

// #include <stdio.h>

// /* 도식 출력 */
// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("[%s] -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list	*n1;
// 	t_list	*n2;
// 	t_list	*n3;

// 	/* NORMAL */
// 	n1 = ft_lstnew("A");
// 	n2 = ft_lstnew("B");
// 	n3 = ft_lstnew("C");
// 	n1->next = n2;
// 	n2->next = n3;

// 	printf("[NORMAL]   ");
// 	print_list(n1);

// 	/* EDGE */
// 	printf("[EDGE]     content == NULL: ");
// 	n2 = ft_lstnew(NULL);
// 	if (n2 && n2->content == NULL && n2->next == NULL)
// 		printf("OK\n");

// 	/* OVERFLOW */
// 	printf("[OVERFLOW] malloc fail: ");
// 	/* 실제 malloc 실패는 강제 불가 → 채점상 테스트 불필요 */
// 	printf("SKIP\n");

// 	return (0);
// }
