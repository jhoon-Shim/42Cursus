/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:57:21 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:54:17 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len ++;
		lst = lst -> next;
	}
	return (len);
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
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;
// 	int		size;

// 	a.content = "A"; a.next = &b;
// 	b.content = "B"; b.next = &c;
// 	c.content = "C"; c.next = NULL;

// 	/* NORMAL */
// 	printf("[NORMAL]   list: ");
// 	print_list(&a);
// 	size = ft_lstsize(&a);
// 	printf("[NORMAL]   size = %d\n", size);

// 	/* EDGE */
// 	printf("[EDGE]     empty list: ");
// 	size = ft_lstsize(NULL);
// 	printf("size = %d\n", size);

// 	/* OVERFLOW */
// 	printf("[OVERFLOW] single node: ");
// 	size = ft_lstsize(&c);
// 	printf("size = %d\n", size);

// 	return (0);
// }
