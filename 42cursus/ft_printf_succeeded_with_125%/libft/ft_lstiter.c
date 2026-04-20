/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:35:07 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 11:44:10 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <unistd.h>

// /* 테스트용 함수 */
// void	apply(void *content)
// {
// 	char	c;

// 	c = *(char *)content;
// 	c += 1;
// 	*(char *)content = c;
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
// 	char	a_c = 'A';
// 	char	b_c = 'B';
// 	char	c_c = 'C';
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;

// 	a.content = &a_c; a.next = &b;
// 	b.content = &b_c; b.next = &c;
// 	c.content = &c_c; c.next = 0;

// 	write(1, "[NORMAL]   before: ", 20);
// 	print_list(&a);

// 	ft_lstiter(&a, apply);

// 	write(1, "[NORMAL]   after:  ", 19);
// 	print_list(&a);

// 	write(1, "[EDGE]     lst == NULL: ", 25);
// 	ft_lstiter(0, apply);
// 	write(1, "OK\n", 3);

// 	write(1, "[OVERFLOW] f == NULL (WILL CRASH)\n", 34);
// 	/* ft_lstiter(&a, 0); */ /* 주석 해제 시 실제 크래시 발생 */

// 	return (0);
// }
