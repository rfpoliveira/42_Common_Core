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

void *routine_mon(void	*table_arg)
{
	t_table *table;
	int	i;

	i = 0;
	table = (t_table *)table_arg;
	while(table->DEATH_WARN == 0)
	{
		if (r_get_time() - table->philos[i].last_eat_time > table->time_die ||
				table->philos[i].meals_eaten == table->max_meals)
		{
			table->DEATH_WARN = 1;
			print_msg(&table->philos[i], DIED);
		}
		i++;
	}
	return (NULL);
}

void  *routine_ph(void	*philo_arg)
{
	t_philo *philo;

	philo = (t_philo *)philo_arg;
	if (philo->id % 2 != 0)
		ph_sleep(philo);
	while (philo->table->DEATH_WARN == ALIVE)
	{
		eat(philo);
		if (philo->table->DEATH_WARN == DEAD)
			break ;
		ph_sleep(philo);
		if (philo->table->DEATH_WARN == DEAD)
			break ;
		print_msg(philo, THINK);
	}
	return (NULL);
}

int  create_threads(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->n_phs)
	{
		if (pthread_create(&table->philo_th[i], NULL, &routine_ph, &table->philos[i]) != 0)
			return (1);
	}
	if (pthread_create(table->monitor, NULL, routine_mon, &table) != 0)
		return (1);
	i = -1;
	while (++i < table->n_phs)
	{
		if (pthread_join(table->philo_th[i], NULL) != 0)
			return (1);
	}
	if (pthread_join(*table->monitor, NULL)!= 0)
		return (1);
	return (0);
}
