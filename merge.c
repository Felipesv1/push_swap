/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:51:33 by felperei          #+#    #+#             */
/*   Updated: 2024/01/31 14:57:33 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void split (t_node *source, t_stack *front, t_stack *back)
{
    t_node *slow;
    t_node *fast;

    slow = source;
    fast = source->next;
    
    while (fast)
    {
        fast = fast->next;
        if (fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
    front->head = source;
    back->tail = slow->next;
    slow->next = NULL;
}

t_node *merge(t_node *a, t_node*b)
{
    t_node *result = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

        if (a->value < b->value)
        {
            result = a;
            result->next = merge(a->next, b);
        }else{
            result = b;
            result->next = merge(a, b->next)
        }
        return result;
}

void merge_sort(t_stack *stack_a)
{
    t_node *node_head;
    t_node *front;
    t_node *back;

    node_head = stack_a;
    if ((node_head == NULL) || (node_head->next == NULL))
        return;
    
    split(node_head, &front, &back);

    merge(&front, &back);

    node_head = merge(front, back);
}