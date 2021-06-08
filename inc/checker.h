/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:50:11 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/08 17:33:19 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "push_swap.h"

int		get_next_line(int fd, char **line);
int		validate_instruction(t_stack *a, t_stack *b, char *instruction);
void	print_stacks(t_stack *a, t_stack *b, char *instruction);

#endif