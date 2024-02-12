/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:11:14 by felperei          #+#    #+#             */
/*   Updated: 2024/02/12 15:45:54 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "stdbool.h"

typedef struct l_node
{
    long value;
    int index;
    struct l_node *next;
} t_node;

typedef struct l_stack{
    t_node *head;
    t_node *tail;
    int size;
}t_stack;



int sa(t_stack *stack_a);
int sb(t_stack *stack_b);
int ss(t_stack *stack_a, t_stack *stack_b);
int ra(t_stack *stack_a);
int rb(t_stack *stack_b);
int rr(t_stack *stack_a, t_stack *stack_b);
int rra(t_stack *stack_a);
int rrb(t_stack *stack_b);
int rrr(t_stack *stack_a, t_stack *stack_b);
int pa(t_stack *stack_a, t_stack *stack_b);
int pb(t_stack *stack_b, t_stack *stack_a);
void rra3(t_stack *stack_a);
t_node *add_node_to_bottom(int n, t_stack *p);
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
void sort_small (t_stack *stack_a, t_stack *stack_b);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void little(t_stack *stack_a);
int find_midle(t_stack *stack_a);
int get_max_index(t_stack *stack);
void radix_sort(t_stack *stack_a, t_stack*stack_b);
// int get_min_index(t_stack *stack);
void set_index(t_stack *stack);
#endif
