/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/31 12:53:21 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tests(t_stack *a, t_stack *b, int argc)
{
	print_stacks(a, b, "init");
	
	rotate_stack(a);
	print_stacks(a, b, "ra");

	swap_stack(a);
	print_stacks(a, b, "sa");
	
	push_stack(a, b);
	print_stacks(a, b, "pb");
	push_stack(a, b);
	print_stacks(a, b, "pb");
	push_stack(a, b);
	print_stacks(a, b, "pb");
	push_stack(a, b);
	print_stacks(a, b, "pb");
	push_stack(a, b);
	print_stacks(a, b, "pb");
	push_stack(a, b);
	
	push_stack(b, a);
	print_stacks(a, b, "pa");
	push_stack(b, a);
	print_stacks(a, b, "pa");
	push_stack(b, a);
	print_stacks(a, b, "pa");
	push_stack(b, a);
	print_stacks(a, b, "pa");
	push_stack(b, a);
	print_stacks(a, b, "pa");
	push_stack(b, a);
	print_stacks(a, b, "pa");
	push_stack(b, a);
	print_stacks(a, b, "pa");

	swap_stack(b);
	print_stacks(a, b, "sb");
	
	rotate_stack(b);
	print_stacks(a, b, "rb");
	rotate_stack(b);
	print_stacks(a, b, "rb");
	rotate_stack(a);
	print_stacks(a, b, "ra");
	
	rev_rotate_stack(a);
	print_stacks(a, b, "rra");
	rev_rotate_stack(a);
	print_stacks(a, b, "rra");
	rev_rotate_stack(a);
	print_stacks(a, b, "rra");
	rev_rotate_stack(b);
	print_stacks(a, b, "rrb");
	
	printf(ANSI_F_GREEN"sorted list (0:sorted):%d"ANSI_RESET"\n",
		check_sorted(a, argc));
}

void	do_sort(t_stack *a, t_stack *b, int argc)
{
	// if (argc <= 4)
	// {
	// 	sort_3(a);
	// }
	// else if (argc <= 10)
	// {
		sort_5(a, b, argc);
	// }
	// else
	// 	sort_algorithm(a, b, argc);
}

void	init_stack(t_stack *s, int argc)
{
	s->size = 0;
	s->stack = malloc(sizeof(int) * (argc - 1));
	s->change_top = 0;
	s->change_bottom = 0;
	s->change_total = 0;
}

int	main(int argc, char **argv)
{
	int		valid_list;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	else
	{
		valid_list = validate_args(argc, argv);
		check_arg_error(valid_list);
		init_stack(&a, argc);
		init_stack(&b, argc);
		load_stack(argc, argv, &a);
	}
	// tests(&a, &b, argc);
	if (check_sorted(&a, argc - 1) == EXIT_FAILURE)
	{
		print_stacks(&a, &b, "init");
		do_sort(&a, &b, argc);
		//print_stacks(&a, &b, "end");
		//print_sorted(&a, argc - 1);
	}
	// else
	// {
	// 	print_stacks(&a, &b, "ok");
	// 	print_sorted(&a, argc - 1);
	// }
	free(a.stack);
	free(b.stack);
}
