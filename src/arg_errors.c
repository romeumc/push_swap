/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:57:32 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 15:46:44 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	check_arg_error(int valid_list)
{
	if (valid_list == 1)
	{
		exit (EXIT_SUCCESS);
	}
	else if (valid_list == 2)
	{
		print_error();
		exit (EXIT_FAILURE);
	}
	else if (valid_list == 3)
	{
		print_error();
		exit (EXIT_FAILURE);
	}
}
