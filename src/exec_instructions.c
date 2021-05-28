/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:43:01 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/28 21:47:10 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_swap(t_list **list, char *instruction)
{
	swap_list(list);
	ft_putstr(instruction);
	if (instruction != NULL)
		ft_putstr("\n");
}

void	exec_push(t_list **src, t_list **dest, char *instruction)
{
	push_list(src, dest);
	ft_putstr(instruction);
	ft_putstr("\n");
}

void	exec_rotate(t_list **list, char *instruction)
{
	rotate_list(list);
	ft_putstr(instruction);
	if (instruction != NULL)
		ft_putstr("\n");
}

void	exec_rev_rotate(t_list **list, char *instruction)
{
	rev_rotate_list(list);
	ft_putstr(instruction);
	if (instruction != NULL)
		ft_putstr("\n");
}
