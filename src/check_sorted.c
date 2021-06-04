/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:17:59 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 11:09:28 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_rev_sorted(t_list *list, int argc)
// {
// 	int	sorted;
// 	int	size;

// 	sorted = EXIT_SUCCESS;
// 	size = ft_lstsize(list);
// 	if (size != argc - 1)
// 		return (EXIT_FAILURE);
// 	while (list->next && size > 1)
// 	{
// 		if (ft_atoi(list->content) < ft_atoi(list->next->content))
// 			sorted = EXIT_FAILURE;
// 		list = list->next;
// 	}
// 	if (sorted == EXIT_SUCCESS)
// 		return (EXIT_SUCCESS);
// 	else
// 		return (EXIT_FAILURE);
// }

// int	check_sorted(t_list *list, int argc)
// {
// 	int	sorted;
// 	int	size;

// 	sorted = EXIT_SUCCESS;
// 	size = ft_lstsize(list);
// 	if (size != argc - 1)
// 		return (EXIT_FAILURE);
// 	while (list->next && size > 1)
// 	{
// 		if (ft_atoi(list->content) > ft_atoi(list->next->content))
// 			sorted = EXIT_FAILURE;
// 		list = list->next;
// 	}
// 	if (sorted == EXIT_SUCCESS)
// 		return (EXIT_SUCCESS);
// 	else
// 		return (EXIT_FAILURE);
// }

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
