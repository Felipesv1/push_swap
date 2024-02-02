/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:51:33 by felperei          #+#    #+#             */
/*   Updated: 2024/02/02 13:30:59 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void split (t_node *source, t_node **front, t_node **back)
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
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

t_node *merge(t_node *node_left, t_node *node_right)
{
    t_node *result = NULL;
    if (node_left == NULL)
        return node_right;
    else if (node_right == NULL)
        return node_left;

        if (node_left->value < node_right->value)
        {
            result = node_left;
            result->next = merge(node_left->next, node_right);
        }else{
            result = node_right;
            result->next = merge( node_left, node_right->next);
        }
        return result;
}

void merge_sort(t_node **node_head)
{
    t_node *head = *node_head;
    t_node *front_left;
    t_node *front_right;
    if ((head == NULL) || (head->next == NULL))
        return;
    
    split(head, &front_left, &front_right);
    merge_sort(&front_left);
    merge_sort(&front_right);

     *node_head = merge(front_left, front_right);
}