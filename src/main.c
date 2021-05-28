/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/28 23:58:17 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tests(t_list **list_a, t_list **list_b, int argc)
{
	printf(ANSI_F_CYAN"list_a size:%d"ANSI_RESET"\n", ft_lstsize(*list_a));
	printf("MIN:%d \t MAX:%d\n", get_min_list(*list_a), get_max_list(*list_a));
	print_lists(list_a, list_b, "INIT");
	swap_list(list_a);
	print_lists(list_a, list_b, "sa");
	push_list(list_a, list_b);
	print_lists(list_a, list_b, "pb");
	push_list(list_a, list_b);
	print_lists(list_a, list_b, "pb");
	push_list(list_a, list_b);
	print_lists(list_a, list_b, "pb");
	swap_list(list_b);
	print_lists(list_a, list_b, "sb");
	rotate_list(list_b);
	print_lists(list_a, list_b, "rb");
	rotate_list(list_a);
	print_lists(list_a, list_b, "ra");
	rev_rotate_list(list_b);
	print_lists(list_a, list_b, "rrb");
	rev_rotate_list(list_a);
	print_lists(list_a, list_b, "rra");
	rev_rotate_list(list_b);
	print_lists(list_a, list_b, "rrb");
	rev_rotate_list(list_a);
	print_lists(list_a, list_b, "rra");
	printf(ANSI_F_GREEN"sorted list (0:sorted):%d"ANSI_RESET"\n",
		check_sorted(*list_a, argc));
}

void	do_sort(t_list **list_a, t_list **list_b, int argc)
{
	t_util	s;

	if (argc <= 4)
	{
		//printf("lista <= 3");
		sort_3(list_a, &s);
	}
	else if (argc <= 6)
	{
		sort_5(list_a, list_b, &s);
	}
	else
		sort_algorithm(list_a, list_b, argc);

}

int	main(int argc, char **argv)
{
	int		valid_list;
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	else
	{
		valid_list = validate_args(argc, argv);
		check_arg_error(valid_list);
		list_a = load_list(argc, argv);
		list_b = NULL;
	}
	//tests(&list_a, &list_b, argc);
	if (check_sorted(list_a, argc) != EXIT_SUCCESS)
	{
		print_lists(&list_a, &list_b, "INIT");
		do_sort(&list_a, &list_b, argc);
		print_lists(&list_a, &list_b, "END");
		print_sorted(list_a, argc);
	}
	//printf(ANSI_F_GREEN"sorted list (0:sorted):%d"ANSI_RESET"\n", check_sorted(list_a, argc));
	free_list(list_a);
	free_list(list_b);
}
