/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:12:51 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/20 12:16:49 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sig;
	long	res;

	res = 0;
	i = 0;
	sig = 1;
	if (str[i] == '-')
	{
		sig *= -1;
		i++;
	}
	if (str[i] == '+' && str[i - 1] != '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * sig);
}

int node_count(t_node *a)
{
	int	i;
	
	i = 1;
	if (a == a->next)
		return (1);
	a = a->next;
	while(a->first != 1)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void  sort3(t_node **a, t_node *b)
{
	while(ft_is_sort(*a))
	{
		mov_swap(a, &b, "sa");
		*a = (*a)->next;
	}
}

int	ft_is_sort(t_node *a)
{
	if (!(a->next))
		return (0);
	a = go_first_node(a);
	a = a->next;
	while(1)
	{
		if (a->prev->numb > a->numb)
			return (1);
		a = a->next;
		if (a->first == 1)
			break;
	}
	return (0);
}

void  is_cheap(t_node **a)
{
	(*a)->cheap = 1;
	*a = (*a)->next;
	while((*a)->first != 1)
	{
		if ((*a)->index < (*a)->prev->index)
		{
			(*a)->prev->cheap = 0;
			(*a)->cheap = 1;
		}
		*a = (*a)->next;
	}
}
