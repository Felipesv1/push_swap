/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:10 by felperei          #+#    #+#             */
/*   Updated: 2024/02/02 14:29:26 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static void free_stacks(t_stack *a, t_stack *b)
{
    free_stack(a);
    free_stack(b);
}
static void check_sorted(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
    }
}
void	ft_free(void **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}
int main(int ac, char **av)
{
    int x;
    int i;

    x = 1;
    
    if (ac >= 2)
    {
        t_stack *a = (t_stack *)malloc(sizeof(t_stack));
        t_stack *b = (t_stack *)malloc(sizeof(t_stack));

       while (av[x])
        {
            initial_Stack(a);
            initial_Stack(b);
                i = 0;
                while (av[x][i])
                {
                    if (!ft_isdigit(av[x][i]))
                        return 1;
                    i++;
                }
                add_node_to_bottom(ft_atol(av[x]), a);
            x++;
        }
        check_args(a);
        check_sorted(a, b);
        // ft_printf("output antes da operação\n");
        // ft_printf("pilha a\t\t\n");

        // print_stack(a);
        // ft_printf("pilha b\t\t\n");

        // print_stack(b);
        // ft_printf("output depois da operação\n");
        // merge_sort(&a->head);
        
        // ft_printf("pilha a\t\t\n");
        // print_stack(a);
        // ft_printf("pilha b\t\t\n");
        // print_stack(b);

    }  
    ft_printf("\n");
}
