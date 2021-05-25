/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:16:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/25 02:07:37 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rev_sort(t_list **list_a, int list_size)
{
	while (list_size > 0)
	{
		ft_putstr("ra\n");
		rotate_list(list_a);
		print_list(*list_a);
		list_size--;
	}

}

void	sort_algorithm(t_list *list_a, t_list *list_b, int argc)
{
	if (check_rev_sorted(list_a, argc) == EXIT_SUCCESS)
	{
		do_rev_sort(&list_a, argc);
		print_lists(list_a, list_b);
	}
}