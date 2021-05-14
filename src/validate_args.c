/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:10:58 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 15:40:29 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnumber(char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = EXIT_SUCCESS;
	if (str[i] == '-' || str[i] == '+')
	{
		flag = EXIT_FAILURE;
		i++;
	}
	while (i < ft_strlen(str))
	{
		if (!(ft_isdigit(str[i])))
			return (EXIT_FAILURE);
		i++;
		flag = EXIT_SUCCESS;
	}
	return (flag);
}

static int	find_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (3);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	validate_args(int argc, char **argv)
{
	int	i;
	int	result;

	i = 1;
	if (argc == 2 && ft_isnumber(argv[i]))
		return (1);
	else
	{
		while (i < argc)
		{
			if (ft_isnumber(argv[i]) == EXIT_FAILURE)
				return (2);
			i++;
		}
	}
	result = find_duplicates(argc, argv);
	return (result);
}
