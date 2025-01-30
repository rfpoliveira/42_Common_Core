/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lockers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:41:18 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/30 17:08:03 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_nphs(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->n_phs_lock);
	i = table->n_phs;
	pthread_mutex_unlock(&table->n_phs_lock);
	return (i);
}

int get_last_eat_time(t_philo *philo)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&philo->get_last_eat_time_lock);
	i = philo->last_eat_time;
	pthread_mutex_unlock(&philo->get_last_eat_time_lock);
	return (i);
}

void	add_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_eaten_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_lock);
}

void  set_last_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eat_time_lock);
	philo->last_eat_time = r_get_time();
	pthread_mutex_unlock(&philo->last_eat_time_lock);
}

size_t	get_start_time(t_table *table)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&table->start_time_lock);
	i = table->start_time;
	pthread_mutex_unlock(&table->start_time_lock);
	return (i);
}
