/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:22:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/25 00:02:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "ft_ansi.h"

t_list	*load_list(int argc, char **argv);
void	free_list(t_list *elem);
void	print_list(t_list *list);
int		validate_args(int argc, char **argv);
void	check_arg_error(int valid_list);

void	swap_list(t_list **list);
void	push_list(t_list **src, t_list **dest);
void	rotate_list(t_list **list);
void	rev_rotate_list(t_list **list);

//void	display_error(char *title, char *description);
void	print_error(void);

#endif