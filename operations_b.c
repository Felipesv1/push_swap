/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:48:14 by felperei          #+#    #+#             */
/*   Updated: 2024/01/24 13:18:17 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_stack *stack_b)
{
    
    t_node *node1 = stack_b->head;
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