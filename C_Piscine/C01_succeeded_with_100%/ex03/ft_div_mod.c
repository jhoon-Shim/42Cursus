/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:28:22 by jshim             #+#    #+#             */
/*   Updated: 2025/10/23 19:22:23 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int main(){

	int a = 7;
	int b = 4;
	int div;
	int mod;

	ft_div_mod(a,b,&div,&mod);

	printf("div = %d, mod = %d", div, mod);
	
	return 0;
}
*/