/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:09:12 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 16:04:51 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(char *title, char *description)
{
	write(1, ANSI_B_BRED, 8);
	write(1, " ", 1);
	write(1, title, ft_strlen(title));
	write(1, " \n", 2);
	write(1, ANSI_RESET, 5);
	write(1, description, ft_strlen(description));
}

static void	check_arg_error(int valid_list)
{
	if (valid_list == 1)
	{
		display_error("Only one number", "List already sorted");
		exit (EXIT_SUCCESS);
	}
	else if (valid_list == 2)
	{
		display_error("Error in list", "Found non integer argument");
		exit (EXIT_FAILURE);
	}
	else if (valid_list == 3)
	{
		display_error("Error in list", "Found duplicate number");
		exit (EXIT_FAILURE);
	}
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
		check_arg_error(valid_list);
		list = load_list(argc, argv);
	}
	printf("list size:%d\n", ft_lstsize(list));
	printf("argc: %d", argc);
	print_list(list);
	free_list(list);
}
