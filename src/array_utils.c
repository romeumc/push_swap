/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:49:00 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/30 02:04:05 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_value(t_stack *s)
{
	int	i;

	i = s->size - 1;
	s->min = INT_MAX;
	while (i >= 0)
	{
		if (s->stack[i] < s->min)
		{
			s->min = s->stack[i];
			s->min_pos = i;
		}
		i--;
	}
}

void	get_max_value(t_stack *s)
{
	int	i;

	i = 0;
	s->max = INT_MIN;
	while (i < s->size)
	{
		if (s->stack[i] > s->max)
			s->max = s->stack[i];
		i++;
	}
}

void	change_detect(t_stack *s)
{
	int	i;
	int	first;

	i = 0;
	first = 0;
	s->change_total = 0;
	if (s->size > 1)
	{
		while (i < s->size - 1)
		{
			if (s->stack[i + 1] > s->stack[i])
			{
				if (first == 0 && i < s->size / 2)
				{
					s->change_bottom = i + 1;
					first = 1;
				}
				s->change_total++;
				s->change_top = s->size - i - 1;
			}
			i++;
		}
	}
}

void	update_stack(t_stack *s, int flag)
{
	if (flag == 1)
	{
		get_max_value(s);
	}
	get_min_value(s);
	change_detect(s);
	if (s->size > 2)
	{
		s->diff_bottom = s->stack[s->size - 1] - s->stack[0];
		s->diff_top = s->stack[s->size - 1] - s->stack[s->size - 2];
	}
}

void	load_stack(int argc, char **argv, t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	j = argc - 1;
	while (i < argc - 1)
	{
		s->stack[i] = ft_atoi(argv[j]);
		i++;
		j--;
	}
	s->size = i;
	update_stack(s, 1);
}
