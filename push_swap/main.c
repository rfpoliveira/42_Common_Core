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
	int args;
	int n;
	t_node *stack_a;

	args = 1;
	n = 0;
	stack_a = NULL;
	if (argc < 2)
		return (ft_printf("Error\n"));
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[n])
			n++;
		args = 0;
	}	
	if (parsing(argv, argc) == -1)
		return (ft_printf("Error\n"));
	stack_a = ft_list_ini(argv + args);
	if (argc == 2)	
		matrix_free(argv);

	while(1)
	{
		ft_printf("%i\n", stack_a->numb);
		stack_a = stack_a->next;
		if (stack_a->first == 1)
			break;
	}

	stack_a = go_first_node(stack_a);
    swap(&stack_a);
	printf("swaped:\n");
	/*char  **buff = malloc(sizeof(char *) * (3 + 1));
	buff[0] = "4";
	buff[1] = "2";
	buff[2] = "3";
	buff[3] = 0x0;
	t_node *b = ft_list_ini(buff);
	push(&stack_a, &b);*/

	while(1)
	{
		ft_printf("%i\n", stack_a->numb);
		stack_a = stack_a->next;
		if (stack_a->first == 1)
			break;
	}
	ft_printf("prev:\n");
	
	stack_a = stack_a->prev;
	while(1)
	{
		ft_printf("%i\n", stack_a->numb);
		stack_a = stack_a->prev;
		if (stack_a->first == 1)
			break ;
	}
	ft_printf("%i\n", stack_a->numb);
	
	/*while(b->next != NULL)
	{
		ft_printf("%i\n", b->numb);
		b = b->next;
	}
	ft_printf("%i\n", b->numb);

*/

	stack_a = stack_a->next;
	while(1)
	{
		if (stack_a->first == 1)
		{
			free(stack_a);
			break ;
		}
		free(stack_a);
		stack_a = stack_a->next;
	}
}
