/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:22:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/14 18:04:58 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "ft_ansi.h"

t_list	*load_list(int argc, char **argv);
// void	free_list(t_list *elem);
// void	print_list(t_list *list);
int		validate_args(int argc, char **argv);
void	display_error(char *title, char *description);
void	check_arg_error(int valid_list);
#endif