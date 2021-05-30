/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:16:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/30 02:11:23 by rmartins         ###   ########.fr       */
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

void	sort_algorithm(t_stack *a, t_stack *b, int argc)
{
	// printf(ANSI_F_BRED"\nA => min:%d max:%d last:%d"ANSI_RESET"\n",
	// 	a->min, a->max, a->stack[a->size - 1]);
	// printf(ANSI_F_BRED"B => min:%d max:%d last:%d"ANSI_RESET"\n",
	// 	b->min, b->max, b->stack[b->size - 1]);

	//printf(ANSI_F_BGREEN"top:%d bottom:%d"ANSI_RESET"\n", a->change_top, a->change_bottom);
	rotate_stack(a);
	print_stacks(a, b, "ra");
	//printf(ANSI_F_BGREEN"top:%d bottom:%d"ANSI_RESET"\n", a->change_top, a->change_bottom);

// 	print_lists(list_a, list_b, "START");
// 	if (check_rev_sorted(*list_a, argc) == EXIT_SUCCESS)
// 	{
// 		printf("AQUI");
// 		//do_rev_sort(list_a, argc);
// 	}
// 	print_lists(list_a, list_b, "END");
	(void)argc;
}

void	sort_3(t_stack *s)
{
	//printf(ANSI_F_YELLOW"\nmin:%d max:%d last:%d"ANSI_RESET"\n", s->min, s->max, s->stack[s->size - 1]);
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


void	sort_bottom0(t_stack *a, t_stack *b)
{
	if (a->change_top == 1)
	{
		if (a->change_total == 1)
		{
			exec_swap(a, "sa");
			print_stacks(a, b, "sa 10");
		}
		//else if (a->stack[a->size - 1] < a->stack[0])
		else if (a->diff_top < a->diff_bottom)
		{
			exec_rev_rotate(a, "rra");
			print_stacks(a, b, "rra 10");
		}
		else if (a->diff_top > a->diff_bottom)
		{
			exec_rotate(a, "ra");
			print_stacks(a, b, "ra 10");
		}
		else
		{
			printf("ERRO 10");
			// exec_swap(a, "sa");
			// print_stacks(a, b, "sa 10");
		}
	}
	else if (a->change_top > 1)
	{
		if (a->change_top == 2 && a->stack[a->size - 1] == a->min
			&& a->stack[a->size - 2] == a->max)
		{
			exec_swap(a, "sa");
			print_stacks(a, b, "sa +0");
		}
		if (a->stack[a->size - 1] == a->min)
		{
			exec_push(a, b, "pb");
			print_stacks(a, b, "pb 01");
		}
		else
		{
			exec_rotate(a, "ra");
			print_stacks(a, b, "ra +0");
		}
	}
}

void	sort_top1_bottom1(t_stack *a, t_stack *b)
{
	// if (a->diff_top < a->diff_bottom)
	// {
	// 	exec_rev_rotate(a, "rra");
	// 	print_stacks(a, b, "rra 11");
	// }
	// else
	// {
	// 	//printf("AQUI dif_top:%d dif_bottom:%d\n", a->diff_top, a->diff_bottom);
	// 	exec_rotate(a, "ra");
	// 	print_stacks(a, b, "ra 11");
	// }
	if (a->min_pos <= a->size / 2)
	{
		exec_rev_rotate(a, "rra");
		print_stacks(a, b, "rra 11");
	}
	else
	{
		exec_rotate(a, "ra");
		print_stacks(a, b, "ra 11");
	}
}

void	sort_5(t_stack *a, t_stack *b, int argc)
{
	int	flag;

	flag = EXIT_FAILURE;
	while(flag == EXIT_FAILURE)
	{
		if (a->stack[a->size -1] == a->min && b->stack[b->size -1] == b->max
			&& check_sorted(a, a->size) == EXIT_SUCCESS)
		{
			exec_push(b, a, "pa");
			print_stacks(a, b, "pa");
		}
		else if (a->size == 3)
			sort_3(a);
		else if (a->change_top == 0 && a->change_bottom == 1)
		{
			if (a->stack[a->size - 1] == a->min)
			{
				exec_push(a, b, "pb");
				print_stacks(a, b, "pb 01");
			}
			else
			{
				exec_rev_rotate(a, "rra");
				print_stacks(a, b, "rra 01");
			}
		}
		else if (a->change_bottom == 0)
			sort_bottom0(a, b);
		else if (a->change_top == 1 && a->change_bottom == 1)
			sort_top1_bottom1(a, b);
		else if (a->change_top > a->change_bottom)
		{
			if (a->stack[a->size - 1] == a->min)
			{
				exec_push(a, b, "pb");
				print_stacks(a, b, "pb +-");
			}
			// else
			// {
			// 	exec_rev_rotate(a, "rra");
			// 	print_stacks(a, b, "rra +-");
			// }
			else if (a->min_pos <= a->size / 2)
			{
				exec_rev_rotate(a, "rra");
				print_stacks(a, b, "rra +-");
			}
			else
			{
				exec_rotate(a, "ra");
				print_stacks(a, b, "ra +-");
			}
		}
		else if (a->change_top < a->change_bottom)
		{
			if (a->stack[a->size - 1] == a->min)
			{
				exec_push(a, b, "pb");
				print_stacks(a, b, "pb -+");
			}
			else if (a->change_top == 1)
			{
				exec_swap(a, "sa");
				print_stacks(a, b, "sa -+");
			}
			// else
			// {
			// 	exec_rotate(a, "ra");
			// 	print_stacks(a, b, "ra -+");
			// }
			else if (a->min_pos <= a->size / 2)
			{
				exec_rev_rotate(a, "rra");
				print_stacks(a, b, "rra -+");
			}
			else
			{
				exec_rotate(a, "ra");
				print_stacks(a, b, "ra -+");
			}
		}
		else if (a->change_top == a->change_bottom)
		{
			if (a->stack[a->size - 1] == a->min)
			{
				exec_push(a, b, "pb");
				print_stacks(a, b, "pb ==");
			}
			//else if (a->diff_top < a->diff_bottom)
			else if (a->min_pos <= a->size / 2)
			{
				exec_rev_rotate(a, "rra");
				print_stacks(a, b, "rra ==");
			}
			else
			{
				exec_rotate(a, "ra");
				print_stacks(a, b, "ra ==");
			}
		}
		else
		{
			printf("ERRO\n");
		}
		//sleep(1);
		flag = check_sorted(a, argc - 1);

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
