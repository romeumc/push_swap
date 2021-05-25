/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/25 02:01:14 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	print_lists(t_list *list_a, t_list *list_b)
{
	write(1, ANSI_F_BRED, 8);
	write(1, " list_a ", 8);
	write(1, ANSI_RESET, 5);
	print_list(list_a);
	write(1, "\t\t", 2);
	write(1, ANSI_F_BRED, 8);
	write(1, " list_b ", 8);
	write(1, ANSI_RESET, 5);
	print_list(list_b);
}

void	tests(t_list *list_a, t_list *list_b, int argc)
{
	printf(ANSI_F_CYAN"list_a size:%d"ANSI_RESET"\n", ft_lstsize(list_a));
	print_lists(list_a, list_b);
	printf(ANSI_F_RED"swap a"ANSI_RESET"\n");
	swap_list(&list_a);
	print_lists(list_a, list_b);
	printf(ANSI_F_RED"push a"ANSI_RESET"\n");
	push_list(&list_a, &list_b);
	push_list(&list_a, &list_b);
	push_list(&list_a, &list_b);
	push_list(&list_a, &list_b);
	print_lists(list_a, list_b);
	printf(ANSI_F_RED"swap b"ANSI_RESET"\n");
	swap_list(&list_b);
	print_lists(list_a, list_b);
	printf(ANSI_F_RED"rotate ab"ANSI_RESET"\n");
	rotate_list(&list_b);
	rotate_list(&list_a);
	print_lists(list_a, list_b);
	printf(ANSI_F_RED"rev rotate ab"ANSI_RESET"\n");
	rev_rotate_list(&list_b);
	rev_rotate_list(&list_a);
	print_lists(list_a, list_b);
	printf(ANSI_F_RED"rev rotate ab"ANSI_RESET"\n");
	rev_rotate_list(&list_b);
	rev_rotate_list(&list_a);
	print_lists(list_a, list_b);
	printf(ANSI_F_GREEN"sorted list (0:sorted):%d"ANSI_RESET"\n",
		check_sorted(list_a, argc));
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
	//tests(list_a, list_b, argc);
	print_lists(list_a, list_b);
	printf(ANSI_F_GREEN"sorted list (0:sorted):%d"ANSI_RESET"\n", check_sorted(list_a, argc));
	if (check_sorted(list_a, argc) != EXIT_SUCCESS)
	{
		printf("ORDENAR\n");
		sort_algorithm(list_a, list_b, argc);
	}
	free_list(list_a);
	free_list(list_b);
}
