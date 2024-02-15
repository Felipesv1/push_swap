/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:10 by felperei          #+#    #+#             */
/*   Updated: 2024/02/15 12:15:46 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static void free_stacks(t_stack *a, t_stack *b)
{
    free_stack(a);
    free_stack(b);
}
static void	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit (-1);
	}
}

int main(int ac, char **av)
{
        t_stack *a = (t_stack *)malloc(sizeof(t_stack));
        t_stack *b = NULL;
        if (ac < 2 )
            return (-1);
        check_args(av, ac);
        init_Stack(a, ac, av);
        if (check_dup(a) == 1)
        {
            ft_printf("Error\n");
            free_stack(a);
            return (-1);
        }
        check_sorted(a, b);
        if (a->size > 3)
            b = (t_stack *)malloc(sizeof(t_stack));
        // ft_printf("output antes da operação\n");
        // ft_printf("pilha a\t\t\n");
        // print_stack(a);

        // ft_printf("pilha b\t\t\n");

        // ft_printf("output depois da operação\n");

            sort_stack(a, b);
            ft_printf("pilha a\t\t\n");
            print_stack(a);
       
         ft_printf("pilha b\t\t\n");
         print_stack(b);
       

    
        free_stacks(a, b);
        return (0);
}