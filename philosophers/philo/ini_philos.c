/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:55:41 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/22 17:19:20 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  *routine(t_table *table)
{
	while (42)
	{

		if (table->deadman == 1)
			break ;
	}
}

int  create_threads(t_table *table)
{
	int i;

	i = 0;
	while (i < table.n_phs)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine, &table) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < table.n_phs)
	{
		if (pthread_join(table->philos[i].thread), NULL) != 0)
			return (-1);
		i++;
	}
}

void  ini_philos(t_philo *philos, int n_phs)
{
	int	i;

	i = 0;
	while (i < n_phs)
	{
		philos[i].eaten = 0;
		philos[i].alive = 1;
	}
}

int  ini_table(int argc, char **info, t_table *table, t_philo philos)
{
	table.n_phs = r_atoi(info[1]);
	table.limit_die = r_atoi(info[2]);
	table.limit_eat = r_atoi(info[3]);
	table.limit_sleep = r_atoi(info[4]);
	if (argc == 6)
		table->max_meals = info[5];
	else
		table->max_meals = -1;
	table.deadman = 0;
	table->philos = philos;
}

