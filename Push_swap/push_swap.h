/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:06 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/22 14:26:57 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

int					swap(t_list **stack);
int					push(t_list **stack_a, t_list **stack_b);
int					rotate(t_list **stack);
int					reverse_rotate(t_list **stack);

int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);

void				sort_5(t_list **stack_a, t_list **stack_b);
void				sort(t_list **stack_a, t_list **stack_b);

void				radix_algo(t_list **stack_a, t_list **stack_b);
void				quicksort(t_list **stack_a, int l, int h);

int					get_dist(t_list **stack, int index);
int					is_sorted(t_list *stack);
void				ft_error(char *msg);
void				ft_free(char **str);
void				free_stack(t_list **stack);

void				ft_check_args(int argc, char **argv);
void				index_stack(t_list **stack);

int					ft_lstsize(t_list *head);
t_list				*ft_lstnew(int value);
void				ft_lstadd_back(t_list **stack, t_list *new);
t_list				*ft_lstlast(t_list *head);

int					main(int argc, char **argv);

#endif
