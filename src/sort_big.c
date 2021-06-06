/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:48:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 15:08:48 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_a_to_b(t_stack *a, t_stack *b,
	int start_size, float start_avg)
{
	int	i;

	i = 0;
	while (i < start_size)
	{
		if (a->stack[a->size] < start_avg)
			exec_push(a, b, "pb");
		else
			exec_rotate(a, "ra");
		i++;
	}
}

void	split_b_to_a(t_stack *a, t_stack *b, int b_size, float b_average)
{
	while (b_size > 0)
	{
		if (b->stack[b->size] == next_to_sort(a, b))
		{
			exec_push(b, a, "pa");
			a->max_sorted = a->stack[a->size];
			exec_rotate(a, "ra");
		}
		else if ((b->size + 1) <= PROCESS_SIZE)
		{
			if (b->stack[b->size] == b->max)
				exec_push(b, a, "pa");
			else if (b->max_pos <= (b->size + 1) / 2 )
				exec_rev_rotate(b, "rrb");
			else
				exec_rotate(b, "rb");
		}
		else if (b->stack[b->size] >= b_average)
			exec_push(b, a, "pa");
		else
			exec_rotate(b, "rb");
		b_size--;
	}
}

void	push_to_b(t_stack *a, t_stack *b, int b_max)
{
	if (b_max == INT_MIN)
	{
		b_max = a->size + 1;
	}
	while (a->stack[a->size] <= b_max && a->stack[a->size] != a->min)
	{
		if (a->stack[a->size] == next_to_sort(a, b)
			&& a->stack[a->size] != a->min)
		{
			a->max_sorted = a->stack[a->size];
			exec_rotate(a, "ra");
		}
		else
			exec_push(a, b, "pb");
	}
	if (b->min == next_to_sort(a, b))
		push_to_a(a, b);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int	max;

	if (b->size + 1 == 0)
		return ;
	max = b->max;
	split_b_to_a(a, b, b->size + 1, b->average);
	while ((a->stack[a->size] == next_to_sort(a, b)
			|| a->stack[a->size] == a->min) && check_sorted(a) == EXIT_FAILURE)
	{
		a->max_sorted = a->stack[a->size];
		exec_rotate(a, "ra");
	}
	push_to_a(a, b);
	push_to_b(a, b, max);
}

void	sort_big(t_stack *a, t_stack *b)
{
	split_a_to_b(a, b, a->size + 1, a->average);
	push_to_a(a, b);
	push_to_b(a, b, a->max);
}
