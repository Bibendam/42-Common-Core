/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:18:56 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/15 15:08:13 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

// swap.c

int					swap(t_list **stack);
int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);

// push.c

int					push(t_list **stack_to, t_list **stack_from);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);

// rotate.c

int					rotate(t_list **stack);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);

// rev_rotate.c

int					rev_rotate(t_list **stack);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);

// sort_utils.c

int					is_sorted(t_list **stack);
int					get_min(t_list **stack, int val);
int					get_distance(t_list **stack, int index);

// sort_small.c

void				sort_small(t_list **stack_a, t_list **stack_b);

// sort_big.c

void				radix_sort(t_list **stack_a, t_list **stack_b);
void				insertion_sort(t_list **stack_a);
void				quicksort(t_list **stack_a, int low, int high);
void				hybrid_quicksort_insertion_sort(t_list **stack_a);

// list_utils.c

t_list				*ft_lstnew(int value);
void				ft_lstadd_back(t_list **stack, t_list *new);
void				ft_lstadd_front(t_list **stack, t_list *new);
t_list				*ft_lstlast(t_list *head);
int					ft_lstsize(t_list *head);

// errors.c

void				ft_error(char *msg);
void				ft_check_args(int argc, char **argv);

// free.c

void				ft_free(char **str);
void				free_stack(t_list **stack);

// index.c

void				index_stack(t_list **stack);

// main.c
int					main(int argc, char **argv);

#endif
