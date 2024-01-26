/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:10 by felperei          #+#    #+#             */
/*   Updated: 2024/01/24 13:30:21 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void inicializaPilha(t_stack *p)
{
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
}
 void add_node_to_bottom(int n, t_stack *p)
{
    t_node *new_node = (t_node*)malloc(sizeof(t_node));

    if (new_node == NULL)
        return;
    
    new_node->value = n;

    if (p->head == NULL)    
    {
        p->head = new_node;
        p->tail = new_node;
        new_node->next = NULL;
    }
    else
    {
        p->tail->next = new_node;
        p->tail = new_node;
        new_node->next = NULL;
    }
    p->size++;
}
void imprimirPilha(t_stack *p){
    t_node *ptr = p->head;
    if (ptr == NULL){
        return;
    }
    else{
        while(ptr)
        {
            ft_printf("%d\n", ptr->value);
            ptr = ptr->next;
        }
    }
}
int main(int ac, char **av)
{
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    t_stack *b = (t_stack *)malloc(sizeof(t_stack));

    inicializaPilha(a);
    inicializaPilha(b);
    int x;
    x = 1;
    char *num = av[x];
    if (ac >= 1)
    {
        if (!(*num >= '0' && *num <= '9'))
        {
            ft_printf("Error\n");
            return -1;
        }
        while (av[x]){
            add_node_to_bottom(ft_atoi(av[x]), a);
            x++;
        }
        ft_printf("output antes da operação\n");
        ft_printf("pilha a\t\t\n");

        imprimirPilha(a);
        ft_printf("pilha b\t\t\n");

        imprimirPilha(b);
        ft_printf("output depois da operação\n");
        pb(b, a);
        pb(b, a);
        pb(b, a);
        rb(b);
        ft_printf("pilha a\t\t\n");
        imprimirPilha(a);
        ft_printf("pilha b\t\t\n");
        imprimirPilha(b);
    }
}