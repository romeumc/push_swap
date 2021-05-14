/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 15:38:47 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*load_list_arg(int argc, char **argv)
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
		printf("arg[%d]: %s\n", i, argv[i]);
		i++;
	}
	return (list);
}

void	display_error(char *title, char *description)
{
	write(1, ANSI_B_BRED, 8);
	write(1, " ", 1);
	write(1, title, ft_strlen(title));
	write(1, " \n", 2);
	write(1, ANSI_RESET, 5);
	write(1, description, ft_strlen(description));
}

int	main(int argc, char **argv)
{
	t_list	*list;
	int		valid_list;

	if (argc < 2)
	{
		display_error("Wrong Usage", "Please provide list of integers");
		return (EXIT_FAILURE);
	}
	else
	{
		valid_list = validate_args(argc, argv);
		if (valid_list == 1)
		{
			display_error("Only one number", "List already sorted");
			return (EXIT_SUCCESS);
		}
		else if (valid_list == 2)
		{
			display_error("Error in list", "One or more Arguments are not integers");
			return (EXIT_FAILURE);
		}
		else if (valid_list == 3)
		{
			display_error("Error in list", "Found duplicate number");
			return (EXIT_FAILURE);
		}
		list = load_list_arg(argc, argv);
	}
	printf("list size:%d\n", ft_lstsize(list));
	printf("argc: %d", argc);
	print_list(list);
	free_list(list);
}
