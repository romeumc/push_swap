/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:30:28 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 15:55:54 by rmartins         ###   ########.fr       */
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
			ft_lstadd_front(&list, temp);
		}
		i++;
	}
	return (list);
}
