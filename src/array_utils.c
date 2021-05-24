/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:49:00 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/24 21:49:01 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*load_stack(int argc, char **argv)
{
	int	i;
	int	j;
	int	*stack;

	i = 0;
	j = argc - 1;
	stack = malloc(sizeof(int) * j);
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[j]);
		i++;
		j--;
	}
	return (stack);
}

void	print_stack(int *stack, int size)
{
	int	i;

	i = 0;
	size--;
	while (i < size)
	{
		printf ("arg[%d]:%d\n", i, stack[i]);
		i++;
	}
}
