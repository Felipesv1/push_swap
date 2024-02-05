/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:31:38 by felperei          #+#    #+#             */
/*   Updated: 2024/02/05 14:30:13 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *stack_a)
{
    int first;
    int second;
    int third;
   
    first = stack_a->head->value;
    second = stack_a->head->next->value;
    third = stack_a->head->next->next->value;

    if ((first > second && second > third && third < first) 
    || (first < second && second > third && third > first)
    ||(first > second && second < third && third > first))
        sa(stack_a);
    
    first = stack_a->head->value;
    second = stack_a->head->next->value;
    third = stack_a->head->next->next->value;

    if (first > second && second < third && third < first)
        ra(stack_a);
    if (first < second && second > third && second > third)
        rra(stack_a);
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
void rra3(t_stack *stack_a)
{
    rra(stack_a);
    rra(stack_a);
    rra(stack_a);
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
void	sort_4(t_stack *stack_a, t_stack *stack_b)
{

    little(stack_a);
    pb(stack_b, stack_a);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}
void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
    little(stack_a);
    pb(stack_b, stack_a);
    sort_4(stack_a, stack_b);
    pa(stack_a, stack_b);
}

