/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:14:56 by feliperei         #+#    #+#             */
/*   Updated: 2024/02/15 20:13:11 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_stack(t_stack *list)
{
    if (list == NULL)
        return;
    t_node *node = list->head;
    t_node *tmp;
    while (node)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(list);
}


int is_sorted(t_stack *list)
{
    t_node *node = list->head;
    
    while (node->next != NULL)
    {
        if (node->value > node->next->value)
            return 0;
        node = node->next;
    }
    return (1);
}
void little(t_stack *stack_a)
{
     t_node *node = stack_a->head;
     t_node *node_tail = stack_a->tail;

     int i = node->value;

     while(node->next)
     {
        if (node->next->value < i)
            i = node->next->value;
        node = node->next;
     }
     node = stack_a->head;
        if (i == node->value)
            return;
     else if (i == node->next->value)
            sa(stack_a);
    else if (i == node_tail->value)
        rra(stack_a);
        else if (i == find_midle(stack_a))
            rra3(stack_a);
    else
    {
        rra(stack_a);
        rra(stack_a);
    }
}
int find_midle(t_stack *stack_a)
{

    t_node *slow;
    t_node *fast;
    int i;
    i = 0;
    slow = stack_a->head;
    fast = stack_a->head->next;
    
    while (fast)
    {
        fast = fast->next;
        if (fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
        i = slow->value;
    return (i);
}