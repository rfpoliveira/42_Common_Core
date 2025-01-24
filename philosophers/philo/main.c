/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:05 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/22 17:02:36 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parsing(int argc, char **argv)
{
	int	i;
	int buff;

	i= argc - 1;
	buff = 0;
	if (argc > 6 || argc < 5 || r_atoi(argv[1]) > 200)
		return (-1);
	if (argc == 6 && r_atoi(argv[5]) < 0)
		return (-1);
	while(i > 0)
	{
		if(!r_isdigit(argv[i]))
			return (-1);
		i--;
	}
	i = 4;
	while (i > 0)
	{
		if (r_atoi(argv[i]) <= 0)
			return (-1);
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (parsing(argc, argv) == -1)
		return (printf("Error! Non valide arguments!"));
	if (ini_table(argc, argv, &table) != 0)
		return (printf("Error allocating memory!\n"));
	ini_philos(&table);
	ini_forks(&table);
	if (create_threads(&table) != 0)
		return (philo_free(&table), printf("Errors creating/joining threads!"));
}
