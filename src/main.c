/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/13 17:43:06 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// void	show_list

int	main(int argc, char **argv)
{
	char	**arg_string;
	t_list	**list;

	if (argc != 2)
	{
		printf("wrong usage");
	}
	else
	{
		printf("lista: %s\n", argv[1]);
		arg_string = ft_split(argv[1], ' ');
		list[0] = ft_lstnew("test");
		
		printf("%d\n", ft_lstsize(list[0]));
	}
}