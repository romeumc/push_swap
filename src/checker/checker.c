/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:31:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/08 19:01:56 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	load_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		result;

	while (get_next_line(0, &line) > 0)
	{
		result = validate_instruction(a, b, line);
		free(line);
		if (result == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	free(line);
	return (result);
}

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
		if (valid_list == 1)
			valid_list = 0;
		check_arg_error(valid_list);
		init_stack(&a, argc);
		init_stack(&b, argc);
		load_stack(argc, argv, &a);
		valid_list = load_instructions(&a, &b);
	}
	if (valid_list == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 2);
	else if (check_sorted(&a) == EXIT_FAILURE)
		printf("KO\n");
	else
		printf("OK\n");
	free(a.stack);
	free(b.stack);
}
