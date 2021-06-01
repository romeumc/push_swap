/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:49:00 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/01 01:22:48 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_max_avg(t_stack *s)
{
	int	i;

	i = 0;
	s->max = INT_MIN;
	s->min = INT_MAX;
	s->average = 0;
	while (i <= s->size)
	{
		if (s->stack[i] > s->max)
		{
			s->max = s->stack[i];
			s->max_pos = i;
		}
		if (s->stack[i] < s->min)
		{
			s->min = s->stack[i];
			s->min_pos = i;
		}
		s->average += s->stack[i];
		i++;
	}
	s->average /= i;
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
		while (i < s->size)
		{
			if (s->stack[i + 1] > s->stack[i])
			{
				if (first == 0)
				{
					s->change_bottom = i + 1;
					first = 1;
				}
				s->change_total++;
				s->change_top = s->size - i;
			}
			i++;
		}
	}
}

void	update_stack(t_stack *s)
{
	get_min_max_avg(s);
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
	s->size = i - 1;
	update_stack(s);
}
