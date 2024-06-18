/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:18:56 by drizzo            #+#    #+#             */
/*   Updated: 2024/06/18 15:54:49 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* Initialization */

t_stack				*fill_stack_values(int ac, char **av);
void				assign_index(t_stack *stack_a, int ac);

/* Sorting Algorithms */

int					is_sorted(t_stack *stack);
void				sort_small(t_stack **stack);
void				sort_5(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);

/* Position */

int					get_lowest_index_position(t_stack **stack);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void				find_best_move(t_stack **stack_a, t_stack **stack_b);
void				do_best_move(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */

void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);

/* Stack Functions */

t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*stack_new(int value);
void				stack_add_bottom(t_stack **stack, t_stack *new);
int					get_stack_size(t_stack *stack);

/* Utils */

void				free_stack(t_stack **stack);
long int			ft_atoi(const char *str);
void				ft_putstr(char *str);
int					nb_abs(int nb);

/* Split */

char				**ft_split(char const *s, char c);

/* Error */

void				exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input Check */

int					is_correct_input(char **av);
int					is_digit(char c);
int					is_sign(char c);
int					nbstr_cmp(const char *s1, const char *s2);

#endif
