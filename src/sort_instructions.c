/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:39:05 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/31 15:21:00 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *s)
{
	int	i;
	int	aux;

	if (s->size > 0)
	{
		i = s->size;
		aux = s->stack[i];
		s->stack[i] = s->stack[i - 1];
		s->stack[i - 1] = aux;
		update_stack(s);
	}
}

void	push_stack(t_stack *src, t_stack *dest)
{
	int	i;
	int	j;

	i = src->size;
	j = dest->size;
	if (i >= 0)
	{
		dest->stack[j + 1] = src->stack[i];
		dest->size++;
		src->size--;
		update_stack(src);
		update_stack(dest);
	}
}

void	rotate_stack(t_stack *s)
{
	int	i;
	int	top;

	i = s->size;
	if (s->size > 0)
	{
		top = s->stack[i];
		i--;
		while (i >= 0)
		{
			s->stack[i + 1] = s->stack[i];
			i--;
		}
		s->stack[0] = top;
		update_stack(s);
	}
}

void	rev_rotate_stack(t_stack *s)
{
	int	i;
	int	bottom;

	i = 0;
	if (s->size > 0)
	{
		bottom = s->stack[0];
		while (i < s->size)
		{
			s->stack[i] = s->stack[i + 1];
			i++;
		}
		s->stack[s->size] = bottom;
		update_stack(s);
	}
}
