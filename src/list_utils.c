/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:30:28 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/29 00:01:42 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *elem)
{
	t_list	*temp;

	while (elem)
	{
		temp = elem->next;
		free(elem);
		elem = temp;
	}
}

t_list	*load_list(int argc, char **argv)
{
	t_list	*temp;
	t_list	*list;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			list = ft_lstnew(argv[i]);
		}
		else
		{
			temp = ft_lstnew(argv[i]);
			ft_lstadd_back(&list, temp);
		}
		i++;
	}
	return (list);
}

int	get_min_list(t_list *list)
{
	int	min;
	int	number;

	min = INT_MAX;
	if (ft_lstsize(list) > 1)
	{
		while (list)
		{
			number = ft_atoi(list->content);
			if (number < min)
				min = number;
			list = list->next;
		}
	}
	return (min);
}

int	get_max_list(t_list *list)
{
	int	max;
	int	number;

	max = INT_MIN;
	if (ft_lstsize(list) > 1)
	{
		while (list)
		{
			number = ft_atoi(list->content);
			if (number > max)
				max = number;
			list = list->next;
		}
	}
	return (max);
}

void	update_util(t_util *s, t_list **list)
{
	t_list *temp;

	s->min = get_min_list(*list);
	s->max = get_max_list(*list);
	if (ft_lstsize(*list) > 3)
	{
		s->n1 = ft_atoi((*list)->content);
		s->n2 = ft_atoi((*list)->next->content);
		s->n3 = ft_atoi((*list)->next->next->content);
		s->n4 = ft_atoi((*list)->next->next->next->content);
	}
	temp = *list;
	s->nn = ft_atoi(ft_lstlast(temp)->content);
}