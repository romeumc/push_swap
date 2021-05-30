/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:43:01 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/29 21:39:15 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_swap(t_stack *s, char *instruction)
{
	swap_stack(s);
	ft_putstr(instruction);
	if (instruction != NULL)
		ft_putstr("\n");
}

void	exec_push(t_stack *src, t_stack *dest, char *instruction)
{
	push_stack(src, dest);
	ft_putstr(instruction);
	ft_putstr("\n");
}

void	exec_rotate(t_stack *s, char *instruction)
{
	rotate_stack(s);
	ft_putstr(instruction);
	if (instruction != NULL)
		ft_putstr("\n");
}

void	exec_rev_rotate(t_stack *s, char *instruction)
{
	rev_rotate_stack(s);
	ft_putstr(instruction);
	if (instruction != NULL)
		ft_putstr("\n");
}
