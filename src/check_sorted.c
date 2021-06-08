/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:17:59 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/08 16:35:21 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_to_sort(t_stack *a, t_stack *b)
{
	if (a->next_to_sort < b->next_to_sort)
		return (a->next_to_sort);
	else
		return (b->next_to_sort);
}

int	check_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size && s->stack[i] > s->stack[i + 1])
		i++;
	if (i == s->size)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

void	print_sorted(t_stack *s)
{
	if (check_sorted(s) == EXIT_FAILURE)
		printf(ANSI_B_RED "FAIL" ANSI_RESET "\n\n");
	else
		printf(ANSI_B_GREEN " OK " ANSI_RESET "\n\n");
}
