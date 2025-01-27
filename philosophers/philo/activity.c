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
	pthread_mutex_lock(&philo->right_fork);
	print_msg(philo, FORK);
	pthread_mutex_lock(&philo->left_fork);
	print_msg(philo, FORK);
	print_msg(philo, EAT);
	r_usleep(philo->table->time_eat);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	philo->meals_eaten++;
	philo->last_eat_time = r_get_time();
	return (0);
}

int	ph_sleep(t_philo *philo)
{
	print_msg(philo, SLEEP);
	r_usleep(philo->table->time_sleep);
	return (0);
}



