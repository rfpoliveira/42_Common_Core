/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:15:10 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/24 11:15:43 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine_mon(void	*arg)
{

}

void  *routine_ph(void	*arg)
{
	while (42)
	{

		if ( == 1)
			break ;
	}
}

int  create_threads(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->n_phs)
	{
		if (pthread_create(&table->philo_th[i], NULL, &routine_ph, &table) != 0)
			return (1);
	}
	if (pthread_create(&table->monitor, NULL, routine_mon, &table) != 0)
		return (1);
	i = -1;
	while (++i < table->n_phs)
	{
		if (pthread_join(table->philo_th[i], NULL) != 0)
			return (1);
	}
	return (0);
}
