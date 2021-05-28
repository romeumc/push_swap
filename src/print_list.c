/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:57:00 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/28 22:53:28 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr((char *)list->content);
		ft_putstr(" ");
		list = list->next;
	}
}

void	print_element(t_list **list, int *size)
{
	ft_putstr((char *)(*list)->content);
	(*size)--;
	*(list) = (*list)->next;
}

void	print_list1(t_list *list_a, int size_a, t_list *list_b, int size_b)
{
	while (size_a > 0 || size_b > 0)
	{
		if (size_a > size_b)
			print_element(&list_a, &size_a);
		else if (size_b > size_a)
		{
			ft_putstr("\t");
			print_element(&list_b, &size_b);
		}
		else
		{
			print_element(&list_a, &size_a);
			ft_putstr("\t");
			print_element(&list_b, &size_b);
		}
		ft_putstr("\n");
	}
	ft_putstr(ANSI_F_CYAN"a"ANSI_RESET"\t"ANSI_F_CYAN"b"ANSI_RESET"\n");
}

void	print_lists(t_list **list_a, t_list **list_b, char *instruction)
{
	ft_putstr(ANSI_B_BRED " ");
	ft_putstr(instruction);
	ft_putstr(" " ANSI_RESET);

	ft_putstr(ANSI_F_BRED " list_a " ANSI_RESET);
	print_list(*list_a);
	ft_putstr("\t\t");
	ft_putstr(ANSI_F_BRED " list_b " ANSI_RESET);
	print_list(*list_b);
	ft_putstr("\n");

	// int	size_a;
	// int	size_b;
	// size_a = ft_lstsize(*list_a);
	// size_b = ft_lstsize(*list_b);
	// print_list1(*list_a, size_a, *list_b, size_b);
}

