/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:16:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/02 15:59:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *s, t_stack *b)
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
	print_stacks(s, b, "sort 3");
}

void	process_after_push(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		if (b->stack[b->size] < b->average)
		{
			// if (b->stack[b->size] == b->min)
			// {
				exec_rotate(b, "rb");
				print_stacks(a, b, "rb process");
			//}
		}
		else if (b->stack[b->size] < b->stack[b->size - 1] && a->stack[a->size] > a->stack[a->size - 1])
		{
			exec_swap(a, NULL);
			exec_swap(b, "ss");
			print_stacks(a, b, "ss process");
		}
		else if (b->stack[b->size] < b->stack[b->size - 1])
		{
			exec_swap(b, "sb");
			print_stacks(a, b, "sb process");
		}
	}
}

void	sort_top1_bottom1(t_stack *a, t_stack *b)
{	
	if (a->change_top == 1)
	{
		if (a->stack[a->size] > a->average && a->stack[a->size - 1] > a->average)
		{
			if (a->diff_bottom < a->diff_top)
			{
				exec_rotate(a, "ra");
				print_stacks(a, b, "ra 11.t");
			}
			else
			{
				exec_swap(a, "sa");
				print_stacks(a, b, "sa 11.1");
			}
		}
		else
		{
			exec_swap(a, "sa");
			print_stacks(a, b, "sa 11.2");
		}
	}
	else if (a->change_bottom == 1)
	{
		if (a->stack[0] < a->stack[a->size])
		{
			exec_rev_rotate(a, "rra");
			print_stacks(a, b, "rra 11.1");
		}
		// if (a->stack[a->size] <= a->average)
		else
		{
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb 11");
			/*****************/
			process_after_push(a, b);
			/*****************/
		}
		// else
		// {
		// 	exec_rev_rotate(a, "rra");
		// 	print_stacks(a, b, "rra 11.2");
		// }
	}

}

void	process_top_changes(t_stack *a, t_stack *b)
{
	int	count;

	count = a->change_top - 1;
	// if (a->stack[a->size] < a->average && check_sorted(a) == EXIT_FAILURE)
	// {
		while (count > 0)
		{
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb -+ while");
			/*****************/
			process_after_push(a, b);
			/*****************/
			count--;
		}
	// }
	// else
	// {
	// 	exec_rotate(a, "ra");
	// 	print_stacks(a, b, "ra -+");
	// }
}


void	process_bottom_changes(t_stack *a, t_stack *b)
{
	int	count;

	count = a->change_bottom;
	if (a->stack[a->size] < a->average && check_sorted(a) == EXIT_FAILURE)
	{
		exec_push(a, b, "pb");
		print_stacks(a, b, "pb +- while");
		
		/*****************/
		process_after_push(a, b);
		/*****************/
	}
	else
	{
		while (count > 0)
		{
			exec_rev_rotate(a, "rra");
			print_stacks(a, b, "rra +-");
			count--;
		}
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	sorted;

	sorted = EXIT_FAILURE;
	while(sorted == EXIT_FAILURE || b->size != -1)
	{
		// return B >> A
		if (a->stack[a->size] == a->min && b->stack[b->size] == b->max
			&& check_sorted(a) == EXIT_SUCCESS)
		{
			exec_push(b, a, "pa");
			print_stacks(a, b, "pa");
			/*****************/
			process_after_push(a, b);
			/*****************/
		}

		else if (check_sorted(a) == EXIT_SUCCESS)
		{
			if (b->max_pos > b->size / 2)
			{
				while (b->stack[b->size] != b->max)
				{
					exec_rotate(b, "rb");
					print_stacks(a, b, "rb sorted");
				}
			}
			else
			{
				while (b->stack[b->size] != b->max)
				{
					exec_rev_rotate(b, "rrb");
					print_stacks(a, b, "rrb sorted");
				}
			}
		}
		
		// SORT 3
		else if (a->size <= 2)
			sort_3(a, b);
		
		
		// MIN at TOP of stack
		else if ((a->min_pos) == (a->size) && check_sorted(a) == EXIT_FAILURE)
		{
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb min");
			/*****************/
			process_after_push(a, b);
			/*****************/
		}

		// MIN at BOTTOM of stack
		else if (a->min_pos == 0)
		{
			exec_rev_rotate(a, "rra");
			print_stacks(a, b, "rra min XX");
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb min XX");
		}

		// MIN at TOP-1
		else if ((a->min_pos) == (a->size - 1))
		{
			if (a->stack[a->size] > a->average)
			{
				exec_rotate(a, "ra");
				print_stacks(a, b, "ra min");
			}
			else
			{
				exec_swap(a, "sa");
				print_stacks(a, b, "sa min");
			}
		}

		else if (a->stack[0] < a->stack[a->size] && a->stack[0] < a->average)
		{
			exec_rev_rotate(a, "rra");
			print_stacks(a, b, "rra bottom");
		}

		else if (a->change_top == 1 || a->change_bottom == 1)
		{
			sort_top1_bottom1(a, b);
		}


		else if (a->change_top > a->change_bottom)
		{
			process_bottom_changes(a, b);
		}


		else if (a->change_top <= a->change_bottom)
		{
			process_top_changes(a, b);
		}
		
		else
		{
			//printf("ERRO ");
		}
		//sleep(1);
		sorted = check_sorted(a);
	}
}
