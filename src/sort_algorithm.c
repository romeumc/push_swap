/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:16:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/29 00:03:58 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	do_rev_sort(t_list **list_a, int list_size)
// {
// 	while (list_size > 0)
// 	{
// 		ft_putstr("ra\n");
// 		rotate_list(list_a);
// 		list_size--;
// 	}
// }

void	sort_algorithm(t_list **list_a, t_list **list_b, int argc)
{
	print_lists(list_a, list_b, "START");
	if (check_rev_sorted(*list_a, argc) == EXIT_SUCCESS)
	{
		printf("AQUI");
		//do_rev_sort(list_a, argc);
	}
	print_lists(list_a, list_b, "END");
}

void	sort_3(t_list **list, t_util *s)
{
	update_util(s, list);
	printf("min:%d max:%d\n last:%d", s->min, s->max, s->nn);
	if (ft_atoi((*list)->content) == s->min)
	{
		exec_swap(list, "sa");
		exec_rotate(list, "ra");
	}
	else if (ft_atoi((*list)->content) == s->max)
	{
		if (ft_atoi((*list)->next->content) == s->min)
			exec_rotate(list, "ra");
		else
		{
			exec_swap(list, "sa");
			exec_rev_rotate(list, "rra");
		}
	}
	else
	{
		if (ft_atoi((*list)->next->content) == s->min)
			exec_swap(list, "sa");
		else
			exec_rev_rotate(list, "rra");
	}
}

void	sort_5(t_list **list_a, t_list **list_b, t_util *s)
{
	update_util(s, list_a);
	printf(ANSI_F_BCYAN"min:%d max:%d n1:%d n2:%d n3:%d n4:%d last:%d"ANSI_RESET"\n", s->min, s->max, s->n1, s->n2, s->n3, s->n4, s->nn);
	
	if (s->n1 > s->n2 && s->n3 > s->n4)
	{
		exec_push(list_a, list_b, "pb");
		exec_push(list_a, list_b, "pb");
		exec_swap(list_a, "ss");
		exec_swap(list_b, NULL);
		exec_push(list_b, list_a, "pa");
		exec_push(list_b, list_a, "pa");
	}
}
