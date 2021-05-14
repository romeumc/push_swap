/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:57:32 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 17:59:20 by rmartins         ###   ########.fr       */
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

void	check_arg_error(int valid_list)
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
