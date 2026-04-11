/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:12:33 by jshim             #+#    #+#             */
/*   Updated: 2025/11/12 23:49:04 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX05_H
# define EX05_H

# include <unistd.h>

int		is_valid_op(char *op);
int		is_by_zero(char op, int nbr);
int		calculate(int nbr1, char op, int nbr2);
int		only_num(char *nbr);

void	ft_putnbr(int nbr);

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);

#endif