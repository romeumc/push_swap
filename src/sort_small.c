/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:16:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 17:49:38 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_top1_bottom1(t_stack *a, t_stack *b)
{	
	if (a->change_top == 1)
	{
		if (a->stack[a->size] > a->average
			&& a->stack[a->size - 1] > a->average)
		{
			if (a->diff_bottom < a->diff_top)
				exec_rotate(a, "ra");
			else
				exec_swap(a, "sa");
		}
		else
			exec_swap(a, "sa");
	}
	else if (a->change_bottom == 1)
	{
		if (a->stack[0] < a->stack[a->size])
			exec_rev_rotate(a, "rra");
		else
		{
			exec_push(a, b, "pb");
			process_after_push(a, b);
		}
	}
}

static void	process_top_changes(t_stack *a, t_stack *b)
{
	int	count;

	count = a->change_top - 1;
	while (count > 0)
	{
		exec_push(a, b, "pb");
		process_after_push(a, b);
		count--;
	}
}

static void	process_bottom_changes(t_stack *a, t_stack *b)
{
	int	count;

	count = a->change_bottom;
	if (a->stack[a->size] < a->average && check_sorted(a) == EXIT_FAILURE)
	{
		exec_push(a, b, "pb");
		process_after_push(a, b);
	}
	else
	{
		while (count > 0)
		{
			exec_rev_rotate(a, "rra");
			count--;
		}
	}
}

static void	sort_small1(t_stack *a, t_stack *b)
{
	if ((a->min_pos) == (a->size) && check_sorted(a) == EXIT_FAILURE)
	{
		exec_push(a, b, "pb");
		process_after_push(a, b);
	}
	else if (a->min_pos == 0)
	{
		exec_rev_rotate(a, "rra");
		exec_push(a, b, "pb");
	}
	else if ((a->min_pos) == (a->size - 1))
	{
		if (a->stack[a->size] > a->average)
			exec_rotate(a, "ra");
		else
			exec_swap(a, "sa");
	}
	else if (a->stack[0] < a->stack[a->size] && a->stack[0] < a->average)
		exec_rev_rotate(a, "rra");
	else if (a->change_top == 1 || a->change_bottom == 1)
		sort_top1_bottom1(a, b);
	else if (a->change_top > a->change_bottom)
		process_bottom_changes(a, b);
	else if (a->change_top <= a->change_bottom)
		process_top_changes(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	while (check_sorted(a) == EXIT_FAILURE || b->size != -1)
	{
		if (a->stack[a->size] == a->min && b->stack[b->size] == b->max
			&& check_sorted(a) == EXIT_SUCCESS)
		{
			exec_push(b, a, "pa");
			process_after_push(a, b);
		}
		else if (check_sorted(a) == EXIT_SUCCESS)
		{
			if (b->max_pos > b->size / 2)
				while (b->stack[b->size] != b->max)
					exec_rotate(b, "rb");
			else
				while (b->stack[b->size] != b->max)
					exec_rev_rotate(b, "rrb");
		}
		else if (a->size <= 2)
			sort_3(a);
		else
			sort_small1(a, b);
	}
}
