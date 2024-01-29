/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:11:14 by felperei          #+#    #+#             */
/*   Updated: 2024/01/29 11:18:22 by felperei         ###   ########.fr       */
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

static void	sort_3(t_stack *stack_a);
#endif
