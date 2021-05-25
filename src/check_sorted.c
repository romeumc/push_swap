/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:17:59 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/25 01:59:20 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rev_sorted(t_list *list, int argc)
{
	int	number1;
	int	number2;
	int	sorted;

	sorted = EXIT_SUCCESS;
	if (ft_lstsize(list) != argc - 1)
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

int	check_sorted(t_list *list, int argc)
{
	int	number1;
	int	number2;
	int	sorted;

	sorted = EXIT_SUCCESS;
	if (ft_lstsize(list) != argc - 1)
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
		if (number1 > number2)
			sorted = EXIT_FAILURE;
	}
	if (sorted == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
