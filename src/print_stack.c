/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:57:00 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/31 14:55:01 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	int	i;

	i = s->size - 1;
	while (i >= 0)
	{
		// ft_putstr(ANSI_F_BLUE);
		// ft_putnbr(i);
		// ft_putstr(ANSI_RESET);
		ft_putnbr(s->stack[i]);
		ft_putstr(" ");
		i--;
	}
	// printf(ANSI_B_CYAN "size[%d] min[%d] max[%d]"ANSI_RESET "\t",
	// 	s->size, s->min, s->max);
}

void	print_stacks(t_stack *a, t_stack *b, char *instruction)
{
	ft_putstr(ANSI_B_BRED " ");
	ft_putstr(instruction);
	ft_putstr(" " ANSI_RESET);
	ft_putstr(ANSI_F_BRED " list_a " ANSI_RESET);
	print_stack(a);
	ft_putstr("\t\t");
	ft_putstr(ANSI_F_BRED " list_b " ANSI_RESET);
	print_stack(b);
	
	printf(ANSI_F_BGREEN"top:%d bottom:%d total:%d"ANSI_RESET, a->change_top, a->change_bottom, a->change_total);
	printf(ANSI_F_CYAN" size:%d min:%d[%d] max:%d avg:%.2f"ANSI_RESET, a->size, a->min, a->min_pos, a->max, a->average);
	printf(ANSI_F_BMAGENTA" size:%d min:%d[%d] max:%d avg:%.2f"ANSI_RESET, b->size, b->min, b->min_pos, b->max, b->average);
	
	printf("\n");
	(void)a;
	(void)b;
	(void)instruction;
}
