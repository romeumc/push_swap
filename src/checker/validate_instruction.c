/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:51:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/08 17:42:53 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	validate_instruction_cont(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strcmp(instruction, "ra") == 0)
		rotate_stack(a);
	else if (ft_strcmp(instruction, "rb") == 0)
		rotate_stack(b);
	else if (ft_strcmp(instruction, "rr") == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (ft_strcmp(instruction, "rra") == 0)
		rev_rotate_stack(a);
	else if (ft_strcmp(instruction, "rrb") == 0)
		rev_rotate_stack(b);
	else if (ft_strcmp(instruction, "rrr") == 0)
	{
		rev_rotate_stack(a);
		rev_rotate_stack(b);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_instruction(t_stack *a, t_stack *b, char *instruction)
{
	int	result;

	result = EXIT_SUCCESS;
	if (ft_strcmp(instruction, "sa") == 0)
		swap_stack(a);
	else if (ft_strcmp(instruction, "sb") == 0)
		swap_stack(b);
	else if (ft_strcmp(instruction, "ss") == 0)
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (ft_strcmp(instruction, "pa") == 0)
		push_stack(b, a);
	else if (ft_strcmp(instruction, "pb") == 0)
		push_stack(a, b);
	else
		result = validate_instruction_cont(a, b, instruction);
	return (result);
}
