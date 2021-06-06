/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:57:00 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 17:24:40 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	int	i;

	i = s->size;
	while (i >= 0)
	{
		if (s->stack[i] <= s->max_sorted)
		{
			ft_putstr(ANSI_F_GREEN);
			ft_putnbr(s->stack[i]);
			ft_putstr(ANSI_RESET);
		}
		else
		{
			ft_putnbr(s->stack[i]);
		}
		ft_putstr(" ");
		i--;
	}
}

void	print_stacks(t_stack *a, t_stack *b, char *instruction)
{
	ft_putstr(ANSI_B_BRED " ");
	ft_putstr(instruction);
	ft_putstr(" \t" ANSI_RESET);
	ft_putstr(ANSI_F_BRED " list_a " ANSI_RESET);
	print_stack(a);
	//ft_putstr("\t\t");
	ft_putstr(ANSI_F_BRED " list_b " ANSI_RESET);
	if (b != NULL)
		print_stack(b);
	

	//printf(ANSI_F_BGREEN"top:%d bottom:%d total:%d"ANSI_RESET, a->change_top, a->change_bottom, a->change_total);
	printf(ANSI_F_CYAN" size:(%d) min:%d[%d] max:%d[%d] avg:%.2f"ANSI_RESET, a->size+1, a->min, a->min_pos, a->max, a->max_pos, a->average);
	printf(" db:%d dt:%d", a->diff_bottom, a->diff_top);
	printf(ANSI_F_YELLOW" size:(%d) min:%d[%d] max:%d[%d] avg:%.2f"ANSI_RESET, b->size+1, b->min, b->min_pos, b->max, b->max_pos, b->average);
	printf(" msa:%d nsa:%d", a->max_sorted, a->next_to_sort);
	printf(" nsb:%d", b->next_to_sort);
	
	printf("\n");
	(void)a;
	(void)b;
	(void)instruction;
}
