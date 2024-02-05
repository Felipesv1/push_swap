/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:10 by felperei          #+#    #+#             */
/*   Updated: 2024/02/05 15:48:08 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static void free_stacks(t_stack *a, t_stack *b)
{
    free_stack(a);
    free_stack(b);
}

int main(int ac, char **av)
{
    int x;
    int i;

    x = 1;
    
    if (ac >= 2)
    {

        t_stack *a = (t_stack *)malloc(sizeof(t_stack));
        t_stack *b = NULL;
       while (av[x])
        {
                i = 0;
                while (av[x][i])
                {
                    
                    if (!ft_isdigit(av[x][i]))
                    {
                        free_stacks(a, b);
                        return 1;
                    }
                    i++;
                }
                add_node_to_bottom(ft_atol(av[x]), a);
            x++;
        }
        if(check_args(a) == 1)
            return (1);
        if (a->size > 3)
            b = (t_stack *)malloc(sizeof(t_stack));
        ft_printf("output antes da operação\n");
        ft_printf("pilha a\t\t\n");

        print_stack(a);
        ft_printf("pilha b\t\t\n");

        //  print_stack(b);
        ft_printf("output depois da operação\n");
         sort_3(a);
        //merge_sort(&a->head);

        ft_printf("pilha a\t\t\n");
         print_stack(a);
        ft_printf("pilha b\t\t\n");
        // print_stack(b);
        free_stacks(a, b);
    }  
    ft_printf("\n");
}