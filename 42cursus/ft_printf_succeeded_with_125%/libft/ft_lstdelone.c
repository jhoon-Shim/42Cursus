/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:20:16 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:44:26 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

// #include <unistd.h>

// /* 테스트용 del */
// void	del(void *content)
// {
// 	write(1, "(del ", 5);
// 	write(1, content, 1);
// 	write(1, ") ", 2);
// }

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

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	b;

// 	b.content = "B";
// 	b.next = 0;

// 	a = (t_list *)malloc(sizeof(t_list));
// 	a->content = "A";
// 	a->next = &b;

// 	write(1, "[NORMAL]   before: ", 20);
// 	print_list(a);

// 	ft_lstdelone(a, del);

// 	write(1, "\n[NORMAL]   after:  ", 21);
// 	print_list(&b);

// 	write(1, "\n[EDGE]     lst == NULL: ", 26);
// 	ft_lstdelone(0, del);
// 	write(1, "OK\n", 3);

// 	write(1, "[OVERFLOW] del == NULL: ", 25);
// 	ft_lstdelone(&b, 0);
// 	write(1, "OK\n", 3);

// 	return (0);
// }
