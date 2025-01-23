/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:32:27 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/22 17:19:12 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// libraries

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

// custom structs

typedef struct s_philo
{
	int meals_eaten;
	int	alive;
	size_t	time_eat;
	size_t	time_die;
	size_t	time_sleep;
	int	n_phs;
}	t_philo;

typedef	struct s_table
{
	t_philo	*philos;
}	t_table;


//functions

//utils
int	r_atoi(const char *str);
int	r_isdigit(char *s);

//threads
int  ini_philos(int  n);

#endif
