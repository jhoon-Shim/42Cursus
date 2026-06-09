/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:29:42 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:43:55 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;

	if (!lst)
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cur;
	}
	*lst = 0;
}

// /* ===================== */
// /*  테스트용 더미 함수   */
// /* ===================== */

// void	del(void *content)
// {
// 	write(1, "(del) ", 6);
// 	(void)content;
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst)
// 		return ;
// 	if (del)
// 		del(lst->content);
// }

// /* ===================== */
// /*  도식 출력 함수       */
// /* ===================== */

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

// /* ===================== */
// /*  main (단독 실행용)   */
// /* ===================== */

// int	main(void)
// {
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;
// 	t_list	*lst;

// 	a.content = "A"; a.next = &b;
// 	b.content = "B"; b.next = &c;
// 	c.content = "C"; c.next = 0;
// 	lst = &a;

// 	write(1, "[NORMAL]   before: ", 20);
// 	print_list(lst);

// 	ft_lstclear(&lst, del);

// 	write(1, "\n[NORMAL]   after:  ", 21);
// 	if (!lst)
// 		write(1, "NULL\n", 5);

// 	write(1, "\n[EDGE]     lst == NULL: ", 26);
// 	ft_lstclear(0, del);
// 	write(1, "OK\n", 3);

// 	write(1, "[OVERFLOW] del == NULL: ", 25);
// 	ft_lstclear(&lst, 0);
// 	write(1, "OK\n", 3);

// 	return (0);
// }