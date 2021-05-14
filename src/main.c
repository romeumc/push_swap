/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 18:00:23 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*load_stack(int argc, char **argv)
{
	int	i;
	int	j;
	int	*stack;

	i = 0;
	j = argc - 1;
	stack = malloc(sizeof(int) * j);
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[j]);
		i++;
		j--;
	}
	return (stack);
}

void	print_stack(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf ("arg[%d]:%d\n", i, stack[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	//t_list	*list;
	int		valid_list;
	int		*stack_a;
	int		*stack_b;

	if (argc < 2)
	{
		display_error("Wrong Usage", "Please provide list of integers");
		return (EXIT_FAILURE);
	}
	else
	{
		valid_list = validate_args(argc, argv);
		check_arg_error(valid_list);
		stack_a = load_stack(argc, argv);
		print_stack(stack_a, argc - 1);
		//list = load_list(argc, argv);
	}
	// printf("list size:%d\n", ft_lstsize(list));
	//print_list(list);
	//free_list(list);
	(void)stack_b;
	free(stack_a);
}
