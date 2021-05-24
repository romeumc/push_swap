/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:39:05 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/25 00:09:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_list **list)
{
	t_list	*first_node;
	t_list	*second_node;

	if (ft_lstsize(*list) > 1)
	{
		first_node = *list;
		second_node = first_node->next;
		*list = second_node;
		first_node->next = second_node->next;
		second_node->next = first_node;
	}
}

void	push_list(t_list **src, t_list **dest)
{
	t_list	*first_node;

	if (ft_lstsize(*src) >= 1)
	{
		first_node = *src;
		*src = first_node->next;
		first_node->next = NULL;
		ft_lstadd_front(dest, first_node);
	}
	//return (list);
}

void	rotate_list(t_list **list)
{
	t_list	*first_node;
	
	if (ft_lstsize(*list) > 1)
	{
		first_node = *list;
		*list = first_node->next;
		first_node->next = NULL;
		ft_lstadd_back(list, first_node);
	}
}

void	rev_rotate_list(t_list **list)
{
	t_list	*last_node;
	t_list	*temp;

	if (ft_lstsize(*list) > 1)
	{
		temp = *list;
		while (temp->next->next != NULL)
			temp = temp->next;
		last_node = temp->next;
		temp->next = NULL;
		ft_lstadd_front(list, last_node);
	}
}