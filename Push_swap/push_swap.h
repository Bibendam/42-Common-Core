/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:06 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 15:36:35 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct Node
{
	int			value;
	int			index;
	struct Node	*next;
	struct Node	*prev;
}				Node;

typedef struct Stack
{
	Node		*top;
}				Stack;

void			push(Stack *stack, Node *node);
Node			*pop(Stack *stack);
void			swap(Node **stack);
void			rotate(Node **stack);
void			reverse_rotate(Node **stack);

void			sa(Node **a);
void			sb(Node **b);
void			ss(Node **a, Node **b);
void			pa(Stack *a, Stack *b);
void			pb(Stack *a, Stack *b);
void			ra(Node **a);
void			rb(Node **b);
void			rr(Node **a, Node **b);
void			rra(Node **a);
void			rrb(Node **b);
void			rrr(Node **a, Node **b);

Stack			*newStack(void);
void			quicksort(Stack *stack, Stack *helper, int low, int high);

int				is_sorted(Node *stack);
void			ft_error(char *msg);
void			ft_free(char **str);
void			free_stack(Node **top);

void			ft_check_args(int argc, char **argv);

Stack			*create_empty_stack(void);
void			index_stack(Node **stack);

Node			*addNode(Node *head, int value);
Node			*newNode(int data);
void			ft_lstadd_back(Node **lst, Node *new);
Node			*ft_lstlast(Node *head);
Node			*lastNode(Node *root);

void			sort_stack(Stack **stack_a, Stack **stack_b);
int				main(int argc, char **argv);

void			print_stack(Node *top);

#endif
