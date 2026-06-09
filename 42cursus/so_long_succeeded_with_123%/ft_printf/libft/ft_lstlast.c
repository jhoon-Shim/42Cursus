/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:06:21 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:44:42 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

// #include <unistd.h>

// /* 도식 출력 */
// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		write(1, "[", 1);
// 		write(1, lst->content, 1);
// 		write(1, "] -> ", 5);
// 		lst = lst->next;
// 	}
// 	write(1, "NULL\n", 5);
// }

// /* 단일 노드 출력 */
// void	print_node(char *label, t_list *node)
// {
// 	write(1, label, 9);
// 	if (!node)
// 	{
// 		write(1, "NULL\n", 5);
// 		return ;
// 	}
// 	write(1, "[", 1);
// 	write(1, node->content, 1);
// 	write(1, "]\n", 2);
// }

// int	main(void)
// {
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;
// 	t_list	*last;

// 	a.content = "A"; a.next = &b;
// 	b.content = "B"; b.next = &c;
// 	c.content = "C"; c.next = 0;

// 	write(1, "[NORMAL]   list: ", 17);
// 	print_list(&a);
// 	last = ft_lstlast(&a);
// 	print_node("[NORMAL] ", last);

// 	write(1, "[EDGE]     single: ", 20);
// 	print_list(&c);
// 	last = ft_lstlast(&c);
// 	print_node("[EDGE]   ", last);

// 	write(1, "[OVERFLOW] NULL: ", 17);
// 	last = ft_lstlast(0);
// 	print_node("[OVERFLOW]", last);

// 	return (0);
// }
