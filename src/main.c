/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/25 00:11:33 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	size--;
	while (i < size - 1 && stack[i] > stack[i + 1])
	{
		i++;
	}
	if (i == size - 1)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	check_sorted_list(t_list *list, int argc)
{
	int	number1;
	int	number2;
	int	sorted;

	sorted = EXIT_SUCCESS;
	if (ft_lstsize(list) != argc)
		return (EXIT_FAILURE);
	while (list)
	{
		number1 = ft_atoi(list->content);
		number2 = number1;
		list = list->next;
		if (list->next != NULL)
			number2 = ft_atoi(list->content);
		else
			break ;
		if (number1 < number2)
			sorted = EXIT_FAILURE;
	}
	if (sorted == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

// t_list	*init_list(void)
// {
// 	t_list *temp;

// 	temp->content = NULL;
// 	temp->next = NULL;
// 	return (temp);
// }


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

int	main(int argc, char **argv)
{
	int		valid_list;
	t_list	*list_a;
	t_list	*list_b;
	
	if (argc < 2)
	{
		print_error();
		//display_error("Wrong Usage", "Please provide list of integers");
		return (EXIT_FAILURE);
	}
	else
	{
		valid_list = validate_args(argc, argv);
		check_arg_error(valid_list);
		//stack_a = load_stack(argc, argv);
		list_a = load_list(argc, argv);
		list_b = 0;
	}
	//stack_a.start = stack_a.list;
	
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
	//push_list(&list_a, &list_b);
	//push_list(&list_a, &list_b);
	//push_list(&list_a, &list_b);
	//push_list(&list_b, &list_a);
	//push_list(&list_b, &list_a);
	print_lists(list_a, list_b);


	printf(ANSI_F_RED"swap b"ANSI_RESET"\n");
	swap_list(&list_b);
	print_lists(list_a, list_b);
	// swap_list(&list_a);
	// push_list(&list_b, &list_a);
	// print_lists(list_a, list_b);

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

	// printf(ANSI_F_CYAN"list start_a size:%d"ANSI_RESET"\n", ft_lstsize(start_a));
	// print_list(start_a);
	//(void)start_a;
	printf(ANSI_F_GREEN"sorted list (0:sorted):%d"ANSI_RESET"\n", check_sorted_list(list_a, argc));
	
	//print_stack(stack_a, argc);
	//printf("sorted array:%d", check_sorted(stack_a, argc));
	//(void)stack_b;
	//free(stack_a);
	
	free_list(list_a);
	free_list(list_b);
}
