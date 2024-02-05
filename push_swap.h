/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:11:14 by felperei          #+#    #+#             */
/*   Updated: 2024/02/05 15:44:35 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"


typedef struct l_node
{
    int value;
    struct l_node *next;
} t_node;

typedef struct l_stack{
    t_node *head;
    t_node *tail;
    int size;
}t_stack;



void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_b, t_stack *stack_a);

void add_node_to_bottom(int n, t_stack *p);
void add_node_to_top(int n, t_stack *p);
void initial_Stack(t_stack *p);
void print_stack(t_stack *p);
void free_stack(t_stack *p);
int is_sorted(t_stack *list);
int check_dup(t_stack *list);
int overflow(t_stack *list);
int check_args(t_stack *list);
long    ft_atol(const char *nptr);
void	sort_3(t_stack *stack_a);
void    sort_4(t_stack *stack_a, t_stack *stack_b);
void    sort_5(t_stack *stack_a, t_stack *stack_b);
void little(t_stack *stack_a);
void merge_sort(t_node **node_head);

#endif
