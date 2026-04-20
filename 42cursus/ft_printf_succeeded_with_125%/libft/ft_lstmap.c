/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 03:12:32 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:46:49 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*last;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	last = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_node;
		else
			last->next = new_node;
		last = new_node;
		lst = lst->next;
	}
	return (new_list);
}

// #include <stdio.h>

// /* ===================== */
// /* 테스트용 함수들       */
// /* ===================== */

// void	*map_fn(void *content)
// {
// 	return (content);
// }

// void	del(void *content)
// {
// 	printf("(del %s) ", (char *)content);
// }

// /* 테스트용 ft_lstnew */
// t_list	*ft_lstnew(void *content)
// {
// 	static t_list	nodes[3];
// 	static int		i;

// 	if (i >= 3)
// 		return (NULL);
// 	nodes[i].content = content;
// 	nodes[i].next = NULL;
// 	return (&nodes[i++]);
// }

// /* 테스트용 ft_lstclear */
// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*tmp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		del((*lst)->content);
// 		*lst = tmp;
// 	}
// }

// /* ===================== */
// /* 도식 출력             */
// /* ===================== */

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("[%s] -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// /* ===================== */
// /* main                  */
// /* ===================== */

// int	main(void)
// {
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;
// 	t_list	*new;

// 	a.content = "A"; a.next = &b;
// 	b.content = "B"; b.next = &c;
// 	c.content = "C"; c.next = NULL;

// 	printf("[NORMAL]   src: ");
// 	print_list(&a);

// 	new = ft_lstmap(&a, map_fn, del);
// 	printf("[NORMAL]   new: ");
// 	print_list(new);

// 	printf("[EDGE]     lst == NULL: ");
// 	new = ft_lstmap(NULL, map_fn, del);
// 	if (!new)
// 		printf("OK\n");

// 	printf("[OVERFLOW] del == NULL: ");
// 	new = ft_lstmap(&a, map_fn, NULL);
// 	if (!new)
// 		printf("OK\n");

// 	return (0);
// }
