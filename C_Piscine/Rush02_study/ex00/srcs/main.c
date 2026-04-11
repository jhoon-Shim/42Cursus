/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.campus>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/08 15:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	print_error(void)
{
	put_err("Error\n");
}

static void	print_dict_error(void)
{
	put_err("Dict Error\n");
}

static int	run_once(const char *dict_path, const char *num_arg)
{
	char	*norm;
	t_dict	dict;

	norm = NULL;
	if (!normalize_number(num_arg, &norm))
		return (print_error(), 1);
	if (!dict_init(&dict) || !dict_load(&dict, dict_path))
		return (free(norm), print_dict_error(), 1);
	if (!print_number_words(&dict, norm))
		return (dict_free(&dict), free(norm), print_dict_error(), 1);
	dict_free(&dict);
	free(norm);
	return (0);
}

int	main(int argc, char **argv)
{
	const char	*dict_path;
	const char	*num_arg;

	dict_path = "numbers.dict";
	num_arg = NULL;
	if (argc == 2)
		num_arg = argv[1];
	else if (argc == 3)
	{
		dict_path = argv[1];
		num_arg = argv[2];
	}
	else
		return (print_error(), 1);
	return (run_once(dict_path, num_arg));
}
