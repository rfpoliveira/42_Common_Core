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
// Macros

#define ERROR_MALLOC 2

// custom structs

typedef struct s_philo
{
	int	id;
	int meals_eaten;
	int	alive;
	pthread_mutex_t right_fork;
	pthread_mutex_t left_fork;
	//TODO: mutex
	size_t last_eat_time;
	struct s_table *table;
}	t_philo;

typedef	struct s_table
{
	size_t	time_die;
	size_t	time_eat;
	size_t	time_sleep;
	int		n_phs;
	int		max_meals;
	t_philo	*philos;
	pthread_t *philo_th;
	pthread_t monitor;
	pthread_mutex_t *forks;
// TODO:MUTEX;
}	t_table;


//functions

//utils
int	r_atoi(const char *str);
int	r_isdigit(char *s);
size_t r_get_time(void);
int	r_usleep(size_t sleeptime);

//inicialize
void  ini_philos(t_table * table);
int  ini_table(int argc, char **info, t_table *table);
void  ini_forks(t_table *table);

//threads
int  create_threads(t_table *table);

//handle memory
void philo_free(t_table *table);

#endif
