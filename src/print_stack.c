/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:57:00 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/30 02:10:29 by rmartins         ###   ########.fr       */
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
	// ft_putstr(ANSI_B_BRED " ");
	// ft_putstr(instruction);
	// ft_putstr(" " ANSI_RESET);
	// ft_putstr(ANSI_F_BRED " list_a " ANSI_RESET);
	// print_stack(a);
	// ft_putstr("\t\t");
	// ft_putstr(ANSI_F_BRED " list_b " ANSI_RESET);
	// print_stack(b);
	
	// ft_putstr(ANSI_F_BGREEN"top:");
	// ft_putnbr(a->change_top);
	// ft_putstr(" bottom:");
	// ft_putnbr(a->change_bottom);
	// ft_putstr(" total:");
	// ft_putnbr(a->change_total);
	// ft_putstr(ANSI_RESET);

	// ft_putstr(ANSI_F_CYAN" min:");
	// ft_putnbr(a->min);
	// ft_putstr(" max:");
	// ft_putnbr(a->max);
	// ft_putstr(" size:");
	// ft_putnbr(a->size);
	// ft_putstr(" min_pos:");
	// ft_putnbr(a->min_pos);
	// ft_putstr(ANSI_RESET);

	// ft_putstr(ANSI_F_BMAGENTA" min:");
	// ft_putnbr(b->min);
	// ft_putstr(" max:");
	// ft_putnbr(b->max);
	// ft_putstr(" size:");
	// ft_putnbr(b->size);
	// ft_putstr(ANSI_RESET);

	// ft_putstr("\n");
	(void)a;
	(void)b;
	(void)instruction;
}
