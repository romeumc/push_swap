/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:46:48 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 19:59:29 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *s)
{
	if (s->stack[2] == s->min)
	{
		exec_swap(s, "sa");
		exec_rotate(s, "ra");
	}
	else if (s->stack[2] == s->max)
	{
		if (s->stack[1] == s->min)
			exec_rotate(s, "ra");
		else
		{
			exec_swap(s, "sa");
			exec_rev_rotate(s, "rra");
		}
	}
	else
	{
		if (s->stack[1] == s->min)
			exec_swap(s, "sa");
		else
			exec_rev_rotate(s, "rra");
	}
}

void	process_after_push_edgecase(t_stack *a, t_stack *b)
{
	if (a->stack[2] == a->max && a->stack[1] == a->min)
	{
		exec_rotate(a, NULL);
		exec_rotate(b, "rr");
	}
	else if (a->stack[2] == a->min)
	{
		exec_swap(a, NULL);
		exec_swap(b, "ss");
	}
}

void	process_after_push(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		if (b->stack[b->size] < b->average)
		{
			if (a->size == 2)
				process_after_push_edgecase(a, b);
			else
				exec_rotate(b, "rb");
		}
		else if (b->stack[b->size] < b->stack[b->size - 1]
			&& a->stack[a->size] > a->stack[a->size - 1])
		{
			exec_swap(a, NULL);
			exec_swap(b, "ss");
		}
		else if (b->stack[b->size] < b->stack[b->size - 1])
			exec_swap(b, "sb");
	}
}
