/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:16:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/01 01:27:44 by rmartins         ###   ########.fr       */
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


/* void	sort_top1_bottom0(t_stack *a, t_stack *b)
{
	if (a->stack[a->size] > a->average)
	//if (a->min_pos <= a->size / 2)
	{
		exec_rev_rotate(a, "rra");
		print_stacks(a, b, "rra 10");
	}
	else
	{
		exec_swap(a, "sa");
		print_stacks(a, b, "sa 10");
	}

	// // if (a->change_top == 1)
	// // {
	// 	if (a->change_total == 1)
	// 	{
	// 		exec_swap(a, "sa");
	// 		print_stacks(a, b, "sa 10");
	// 	}
	// 	//else if (a->stack[a->size] < a->stack[0])
	// 	else if (a->diff_top < a->diff_bottom)
	// 	{
	// 		exec_rev_rotate(a, "rra");
	// 		print_stacks(a, b, "rra 10");
	// 	}
	// 	else if (a->diff_top > a->diff_bottom)
	// 	{
	// 		exec_rotate(a, "ra");
	// 		print_stacks(a, b, "ra 10");
	// 	}
	// 	else
	// 	{
	// 		printf("ERRO 10");
	// 		// exec_swap(a, "sa");
	// 		// print_stacks(a, b, "sa 10");
	// 	}
	// //}
	// // else if (a->change_top > 1)
	// // {
	// // 	if (a->change_top == 2 && a->stack[a->size] == a->min
	// // 		&& a->stack[a->size - 2] == a->max)
	// // 	{
	// // 		exec_swap(a, "sa");
	// // 		print_stacks(a, b, "sa +0");
	// // 	}
	// // 	if (a->stack[a->size] == a->min)
	// // 	{
	// // 		exec_push(a, b, "pb");
	// // 		print_stacks(a, b, "pb 01");
	// // 	}
	// // 	else
	// // 	{
	// // 		exec_rotate(a, "ra");
	// // 		print_stacks(a, b, "ra +0");
	// // 	}
	// // }
}
*/

// void	sort_one_change_bottom(t_stack *a, t_stack *b)
// {
// 	int i;
// 	int count;

// 	count = a->change_bottom;
// 	i = 0;
// 	while (i <= count)
// 	{
// 		exec_rev_rotate(a, "rra");
// 		i++;
// 	}
// 	while (i > 1)
// 	{
// 		exec_swap(a, "sa");
// 		exec_rotate(a, "ra");
// 		i--;
// 	}
// 	exec_rotate(a, "ra");
// 	print_stacks(a, b, "one bottom");
// 	//(void)b;
// }


void	sort_top1_bottom1(t_stack *a, t_stack *b)
{	
	if (a->change_top == 1)
	{
		if (a->stack[a->size] > a->average && a->stack[a->size - 1] > a->average)
		{
			exec_rotate(a, "ra");
			print_stacks(a, b, "ra 11");
		}
		else
		{
			exec_swap(a, "sa");
			print_stacks(a, b, "sa 11");
		}
	}
	else if (a->change_bottom == 1)
	{
		// if (a->stack[0] < a->stack[a->size])
		// {
		// 	exec_rev_rotate(a, "rra");
		// 	print_stacks(a, b, "rra 11");
		// }
		// else
		// {
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb 11");
			/**********/
				if (b->size > 0)
				{
					if (b->stack[b->size] == b->min_pos)
					{
						exec_rotate(b, "rb");
						print_stacks(a, b, "rb 11");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1] && a->stack[a->size] > a->stack[a->size - 1])
					{
						exec_swap(a, NULL);
						exec_swap(b, "ss");
						print_stacks(a, b, "ss 11");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1])
					{
						exec_swap(b, "sb");
						print_stacks(a, b, "sb 11");
					}
				}
				/**********/
		//}
	}

}


void	sort_5(t_stack *a, t_stack *b)
{
	int	sorted;

	sorted = EXIT_FAILURE;
	while(sorted == EXIT_FAILURE || b->size != -1)
	{
		// if (a->change_total == 1 && a->change_bottom < a->change_top && a->min_pos == a->size)
		// {
		// 	sort_one_change_bottom(a, b);
		// }

		// return B >> A
		if (a->stack[a->size] == a->min && b->stack[b->size] == b->max
			&& check_sorted(a) == EXIT_SUCCESS)
		{
			exec_push(b, a, "pa");
			print_stacks(a, b, "pa");
				/**********/
				if (b->size > 0)
				{
					if (b->stack[b->size] == b->min)
					{
						exec_rotate(b, "rb");
						print_stacks(a, b, "rb +-");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1] && a->stack[a->size] > a->stack[a->size - 1])
					{
						exec_swap(a, NULL);
						exec_swap(b, "ss");
						print_stacks(a, b, "ss +-");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1])
					{
						exec_swap(b, "sb");
						print_stacks(a, b, "sb +-");
					}
				}
				/**********/
		}
		// SORT 3
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
		
		else if (a->size == 2)
			sort_3(a, b);
		
		// MIN at TOP of stack
		else if ((a->min_pos) == (a->size) && check_sorted(a) == EXIT_FAILURE)
		{
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb min");
				/**********/
				if (b->size > 0)
				{
					if (b->stack[b->size] == b->min)
					{
						exec_rotate(b, "rb");
						print_stacks(a, b, "rb min");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1] && a->stack[a->size] > a->stack[a->size - 1])
					{
						exec_swap(b, "ss");
						print_stacks(a, b, "ss min");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1])
					{
						exec_swap(b, "sb");
						print_stacks(a, b, "sb min");
					}
				}
				/**********/
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


		else if (a->change_top == 1 || a->change_bottom == 1)
		{
			sort_top1_bottom1(a, b);
		}

		// else if (a->change_top == 1 && a->change_bottom == 0)
		// 	sort_top1_bottom0(a, b);

		// else if (a->change_top == 1 && a->change_bottom == 1)
		// 	sort_top1_bottom1(a, b);



		// else if (a->change_top == 0 && a->change_bottom == 1)
		// {
		// 	if (a->stack[a->size] == a->min)
		// 	{
		// 		exec_push(a, b, "pb");
		// 		print_stacks(a, b, "pb 01");
		// 	}
		// 	else
		// 	{
		// 		exec_rev_rotate(a, "rra");
		// 		print_stacks(a, b, "rra 01");
		// 	}
		// }


		
		else if (a->change_top > a->change_bottom)
		{
			if (a->stack[a->size] < a->average && check_sorted(a) == EXIT_FAILURE)
			//else if (a->min_pos <= a->size / 2)
			{
				// exec_rev_rotate(a, "rra");
				// print_stacks(a, b, "rra +-");
				exec_push(a, b, "pb");
				print_stacks(a, b, "pb ++");
				
				/**********/
				if (b->size > 0)
				{
					if (b->stack[b->size] == b->min)
					{
						exec_rotate(b, "rb");
						print_stacks(a, b, "rb +-");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1] && a->stack[a->size] > a->stack[a->size - 1])
					{
						exec_swap(b, "ss");
						print_stacks(a, b, "ss +-");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1])
					{
						exec_swap(b, "sb");
						print_stacks(a, b, "sb +-");
					}
				}
				/**********/
			}
			else
			{
				exec_rotate(a, "ra");
				print_stacks(a, b, "ra +-");
			}
		}


		else if (a->change_top <= a->change_bottom)
		{
			if (a->stack[a->size] < a->average && check_sorted(a) == EXIT_FAILURE)
			{
				exec_push(a, b, "pb");
				print_stacks(a, b, "pb -+");
				/**********/
				if (b->size > 0)
				{
					if (b->stack[b->size] == b->min)
					{
						exec_rotate(b, "rb");
						print_stacks(a, b, "rb -+");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1] && a->stack[a->size] > a->stack[a->size - 1])
					{
						exec_swap(b, "ss");
						print_stacks(a, b, "ss -+");
					}
					else if (b->stack[b->size] < b->stack[b->size - 1])
					{
						exec_swap(b, "sb");
						print_stacks(a, b, "sb -+");
					}
				}
				/**********/
			}
			else
			{
				exec_rotate(a, "ra");
				print_stacks(a, b, "ra -+");
			}
		}
		// else if (a->change_top == a->change_bottom)
		// {
		// 	// if (a->stack[a->size] == a->min)
		// 	// {
		// 	// 	exec_push(a, b, "pb");
		// 	// 	print_stacks(a, b, "pb ==");
		// 	// }
		// 	if (a->stack[a->size] > a->average)
		// 	//else if (a->min_pos <= a->size / 2)
		// 	{
		// 		exec_rev_rotate(a, "rra");
		// 		print_stacks(a, b, "rra ==");
		// 	}
		// 	else
		// 	{
		// 		exec_rotate(a, "ra");
		// 		print_stacks(a, b, "ra ==");
		// 	}
		// }
		else
		{
			//printf("ERRO ");
		}
		//sleep(1);
		sorted = check_sorted(a);

		//ft_putstr("ERRROO");
	}
// 	if (s->n1 > s->n2 && s->n3 > s->n4)
// 	{
// 		exec_push(list_a, list_b, "pb");
// 		exec_push(list_a, list_b, "pb");
// 		exec_swap(list_a, "ss");
// 		exec_swap(list_b, NULL);
// 		exec_push(list_b, list_a, "pa");
// 		exec_push(list_b, list_a, "pa");
// 	}
}
