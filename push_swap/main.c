/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:05:11 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/17 10:13:39 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main (int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	argv = parsing(argc, argv);
	if (!argv)
		return (ft_printf("Error\n"));
	stack_a = ft_list_ini(argv);
	if (argc == 2)	
		matrix_free(argv);
	algoritm(&stack_a, &stack_b);
	while(stack_a->next)
	{
		ft_printf("number: %i\nindex:%i\n", stack_a->numb, stack_a->index);
		stack_a = stack_a->next;
	}
	ft_printf("number: %i\nindex:%i\nprev:\n%i\n", stack_a->numb, stack_a->index , stack_a->numb);
	stack_a = stack_a->prev;	
	while(stack_a->prev)
	{
		ft_printf("number: %i\nindex: %i\n", stack_a->numb, stack_a->index);
		stack_a = stack_a->prev;
	}
	ft_printf("number: %i\nindex: %i\n", stack_a->numb, stack_a->index);
	free_lst(stack_a);
	//free_lst(stack_b);
}
