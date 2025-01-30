/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lockers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:36 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/30 16:38:35 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_DEATH_WARN(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->warn_lock);
	i = table->DEATH_WARN;
	pthread_mutex_unlock(&table->warn_lock);
	return (i);
}

int	get_id(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->table->id_lock);
	i = philo->id;
	pthread_mutex_unlock(&philo->table->id_lock);
	return (i);
}

size_t	get_time_eat(t_table *table)
{
	size_t i;

	i = 0;
	pthread_mutex_lock(&table->time_eat_lock);
	i = table->time_eat;
	pthread_mutex_lock(&table->time_eat_lock);
	return (i);
}

size_t	get_time_die(t_table *table)
{
	size_t i;

	i = 0;
	pthread_mutex_lock(&table->time_die_lock);
	i = table->time_die;
	pthread_mutex_lock(&table->time_die_lock);
	return (i);
}

size_t	get_time_sleep(t_table *table)
{
	size_t i;

	i = 0;
	pthread_mutex_lock(&table->time_sleep_lock);
	i = table->time_sleep;
	pthread_mutex_lock(&table->time_sleep_lock);
	return (i);
}


