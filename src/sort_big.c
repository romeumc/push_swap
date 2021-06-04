/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:48:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 13:14:06 by rmartins         ###   ########.fr       */
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

void	push_b_lower_than_average(t_stack *a, t_stack *b,
	int start_size, float start_avg)
{
	int	i;

	i = 0;
	while (i < start_size)
	{
		if (a->stack[a->size] < start_avg)
		{
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb lower than avg");
		}
		else
		{
			exec_rotate(a, "ra");
			print_stacks(a, b, "ra lower than avg");
		}
		i++;
	}
}

void	push_a_inplace(t_stack *a, t_stack *b)
{
	if (b->stack[b->size] == b->max)
	{
		exec_push(b, a, "pa");
		print_stacks(a, b, "pa max");
	}
	else
	{
		if (b->stack[b->size] == next_to_sort(a, b))
		{
			exec_push(b, a, "pa");
			a->max_sorted = a->stack[a->size];
			exec_rotate(a, "ra");
			print_stacks(a, b, "pa ra inplace");
		}
		else
		{
			if (b->max_pos <= (b->size + 1) / 2 )
			{
				exec_rev_rotate(b, "rrb");
				print_stacks(a, b, "rrb smart_rotate");
			}
			else
			{
				exec_rotate(b, "rb");
				print_stacks(a, b, "rb smart_rotate");
			}
		}
	}
}

void	push_a_aproximate(t_stack *a, t_stack *b,
	int start_size, float start_avg)
{
	int	i;

	i = 0;
	while (i < start_size)
	{
		if ((b->size + 1) <= PROCESS_SIZE)
		{
			push_a_inplace(a, b);
		}
		else
		{
			if (b->stack[b->size] >= start_avg)
			{
				exec_push(b, a, "pa");
				print_stacks(a, b, "pa approximate");
			}
			else
			{
				if (b->stack[b->size] == next_to_sort(a, b))
				{
					exec_push(b, a, "pa");
					a->max_sorted = a->stack[a->size];
					exec_rotate(a, "ra");
					print_stacks(a, b, "pa ra approximate");
				}
				else
				{
					exec_rotate(b, "rb");
					print_stacks(a, b, "rb ************************");
				}
				
			}
		}
		i++;
	}
}

void	push_swap(t_stack *a, t_stack *b);
void	backtrack(t_stack *a, t_stack *b, int b_max)
{
	if (b_max == INT_MIN)
	{
		b_max = a->size + 1;
	}
	while (a->stack[a->size] <= b_max && a->stack[a->size] != a->min)
	{
		if (a->stack[a->size] == next_to_sort(a, b) && a->stack[a->size] != a->min)
		{
			a->max_sorted = a->stack[a->size];
			exec_rotate(a, "ra");
			print_stacks(a, b, "ra backtrack");
		}
		else
		{
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb backtrack");
		}
	}
	if (b->min == next_to_sort(a, b))
		push_swap(a, b);
}


void	push_swap(t_stack *a, t_stack *b)
{
	int	max;
	if (b->size + 1 == 0)
		return ;
	max = b->max;
	push_a_aproximate(a, b, b->size + 1, b->average);
	while ((a->stack[a->size] == next_to_sort(a, b) ||
		a->stack[a->size] == a->min) && check_sorted(a) == EXIT_FAILURE)
	{
		a->max_sorted = a->stack[a->size];
		exec_rotate(a, "ra");
		print_stacks(a, b, "ra push_swap");
	}
	push_swap(a, b);
	backtrack(a, b, max);
}


void	sort_big(t_stack *a, t_stack *b)
{
	push_b_lower_than_average(a, b, a->size + 1, a->average);
	push_swap(a, b);
	backtrack(a, b, a->max);
}