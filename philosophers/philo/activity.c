/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:39:11 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/27 12:40:21 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_msg(philo, FORK);
	if (get_nphs(&philo->table) == 1)
	{
		r_usleep(get_time_die(&philo->table));
		return (1);
	}
	pthread_mutex_lock(philo->left_fork);
	print_msg(philo, FORK);
	print_msg(philo, EAT);
	r_usleep(get_time_eat(&philo->table));
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	add_meals_eaten(philo);
	set_last_eat_time(philo);
	return (0);
}

int	ph_sleep(t_philo *philo)
{
	print_msg(philo, SLEEP);
	r_usleep(get_time_sleep(&philo->table));
	return (0);
}



