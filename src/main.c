/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 16:54:53 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, int argc)
{
	s->size = -1;
	s->stack = malloc(sizeof(int) * (argc - 1));
	s->change_top = 0;
	s->change_bottom = 0;
	s->change_total = 0;
	s->max_sorted = INT_MIN;
}

int	main(int argc, char **argv)
{
	int		valid_list;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (EXIT_FAILURE);
	else
	{
		valid_list = validate_args(argc, argv);
		check_arg_error(valid_list);
		init_stack(&a, argc);
		init_stack(&b, argc);
		load_stack(argc, argv, &a);
	}
	if (check_sorted(&a) == EXIT_FAILURE)
	{
		if (argc <= PROCESS_SIZE * 2)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	free(a.stack);
	free(b.stack);
}
