/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:22:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/05/28 23:49:40 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "ft_ansi.h"

typedef struct s_util
{
	int	min;
	int	max;
	int	n1;
	int	n2;
	int	n3;
	int	n4;
	int nn;
} t_util;


t_list	*load_list(int argc, char **argv);
void	free_list(t_list *elem);
int		validate_args(int argc, char **argv);
void	check_arg_error(int valid_list);

void	swap_list(t_list **list);
void	push_list(t_list **src, t_list **dest);
void	rotate_list(t_list **list);
void	rev_rotate_list(t_list **list);

void	exec_swap(t_list **list, char *instruction);
void	exec_push(t_list **src, t_list **dest, char *instruction);
void	exec_rotate(t_list **list, char *instruction);
void	exec_rev_rotate(t_list **list, char *instruction);

int		check_sorted(t_list *list, int argc);
int		check_rev_sorted(t_list *list, int argc);

void	sort_3(t_list **list, t_util *s);
void	sort_5(t_list **list_a, t_list **list_b, t_util *s);
void	sort_algorithm(t_list **list_a, t_list **list_b, int argc);

void	display_error(char *title, char *description);
void	print_error(void);

//void	print_list(t_list *list);
void	print_sorted(t_list *list, int argc);
void	print_lists(t_list **list_a, t_list **list_b, char *instruction);

int		get_min_list(t_list *list);
int		get_max_list(t_list *list);
void	update_util(t_util *s, t_list **list);

#endif