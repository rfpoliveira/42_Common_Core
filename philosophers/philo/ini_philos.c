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

void  *routine()
{
	
}

int  ini_philos(int  n)
{
	pthread philo[n];






}



	int i;

	i = 0;
	while (i < n)
	{
		if (pthread_create(&philo[i]), NULL, &routine, NULL) != 0)
			return (-1);
	}
	i = 0;
	while (i < n)
	{
		if (pthread_join(philo[i]), NULL) != 0)
			return (-1);
	}


}
