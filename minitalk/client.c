/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:37:10 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/08 16:07:49 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int	pid;
	int	bin;

	if (parsing(argc, argv) == -1)
	{
		ft_printf("Check your arguments!");
		return (1);
	}
	i = 0;
	bin = 0;
	j = 0;
	pid = ft_atoi(argv[1]);
	while(argv[2][i])
	{
		bin = encript(argv[2][i]);
		while (j < 8)
		{
			if (bin % 10 == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bin /= 10;
			j++;
		}
		i++;
	}
}
