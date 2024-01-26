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
    t_node *tmp = (t_node *)malloc(sizeof(t_node));
    if (!node1 || !node2)
        return;
    tmp->value = node1->value;
    node1->value = node2->value;
    node2->value = tmp->value;
    free(tmp);
    ft_printf("sb\n");
}
void pb(t_stack *stack_b, t_stack *stack_a)
{
    t_node *node_b1 = stack_b->head;
    t_node *node_a1 = stack_a->head;
    t_node *tmp  = node_a1;
    node_a1 = node_a1->next;
    stack_a->head = node_a1;

    if (node_b1 == NULL)
        {
            node_b1 = tmp;
            node_b1->next = NULL;
            stack_b->head = node_b1; 
        }
        else{
                tmp->next = node_b1;
                stack_b->head = tmp;
        }
        stack_b->size++;
        stack_a->size--;
    ft_printf("pb\n");

}
void rb(t_stack *stack_b)
{
    t_node *node_lst = stack_b->tail;
    t_node *node1 = stack_b->head;
    stack_b->head = node1->next;
    node1->next = NULL;
    node_lst->next = node1;
    ft_printf("rb\n");
}
void rrb(t_stack *stack_b)
{
    t_node *node_lst = stack_b->tail;
    t_node *node1 = stack_b->head;
    t_node *node_penultimate = node1->next->next;

    node_lst->next = node1;
    node_penultimate->next = NULL;
    stack_b->head = node_lst;
    ft_printf("rrb\n");
}