/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:23:58 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:11 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr(ERROR_MSG);
		return (0);
	}
	if (!init_game(&game, argv[1]))
	{
		ft_putstr(ERROR_MSG);
		return (0);
	}
	if (solve_grid(&game, 0))
	{
		print_grid(&game);
	}
	else
	{
		ft_putstr(ERROR_MSG);
	}
	cleanup_game(&game);
	return (0);
}
