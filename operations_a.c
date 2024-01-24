/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:15:05 by felperei          #+#    #+#             */
/*   Updated: 2024/01/24 13:25:55 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stack_a)
{
    
    t_node *node1 = stack_a->head;
    t_node *node2 = node1->next;
    if (!node1 || !node2)
        return;
    {
        int tmp;
        tmp = node1->value;
        node1->value = node2->value;
        node2->value = tmp;
    }
}

// void pa(stack *stack_a, stack *stack_b)
// {

// }