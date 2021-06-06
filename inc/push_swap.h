/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:22:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/04 19:59:49 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "ft_ansi.h"

# define PROCESS_SIZE 12
typedef struct s_stack
{
	int		*stack;
	int		size;
	int		min;
	int		min_pos;
	int		max;
	int		max_pos;
	double	average;
	int		change_top;
	int		change_bottom;
	int		change_total;
	int		diff_top;
	int		diff_bottom;
	int		max_sorted;
	int		next_to_sort;
}	t_stack;

void	load_stack(int argc, char **argv, t_stack *s);
int		check_sorted(t_stack *s);
int		next_to_sort(t_stack *a, t_stack *b);

int		validate_args(int argc, char **argv);
void	check_arg_error(int valid_list);

void	swap_stack(t_stack *s);
void	push_stack(t_stack *src, t_stack *dest);
void	rotate_stack(t_stack *s);
void	rev_rotate_stack(t_stack *s);

void	update_stack(t_stack *s);
void	exec_swap(t_stack *s, char *instruction);
void	exec_push(t_stack *src, t_stack *dest, char *instruction);
void	exec_rotate(t_stack *s, char *instruction);
void	exec_rev_rotate(t_stack *s, char *instruction);

void	sort_small(t_stack *a, t_stack *b);
void	sort_3(t_stack *s);
void	process_after_push_edgecase(t_stack *a, t_stack *b);
void	process_after_push(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	push_to_a(t_stack *a, t_stack *b);

void	display_error(char *title, char *description);
void	print_error(void);

#endif