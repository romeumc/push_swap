/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:30:28 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 14:06:42 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *elem)
{
	t_list		*temp;

	while (elem)
	{
		temp = elem->next;
		free(elem);
		elem = temp;
	}
}

static void	print_element(char *content)
{
	int		len;

	len = 0;
	while (content[len])
		len++;
	write(1, content, len);
	write(1, "\n", 1);
}

void	print_list(t_list *list)
{
	while (list)
	{
		print_element(list->content);
		list = list->next;
	}
}
