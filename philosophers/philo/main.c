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
	if (argc > 6 || argc < 5)
		return (-1);

	//to do: rest of parsing
}

int	main(int argc, char **argv)
{
	if (parsing(argc, argv) == -1)
		return (printf("Error!"));
	if (ini_philos(r_atoi(argv[1])) == -1)
		return (printf("Error creating threads"));
}
