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

void  safe_kill(pid_t pid, int numb)
{
	int	i;

	i = 0;
	i = kill(pid, numb);
	if (i == -1)
	{
		ft_printf("Kill failed!\n");
		exit(1);
	}
}

void  send_char(char *str, pid_t pid)
{
	int	bit;
	int	i;
	char  c;

	i = 0;
	while (str[i])
	{
		bit = 8;
		c = str[i];
		while(bit--)
		{
			if (c >> bit & 1)
				safe_kill(pid, SIGUSR1);
			else
				safe_kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	pid_t	pid;

	if (parsing(argc, argv) == -1)
	{
		ft_printf("Usage = ./client <PID> <MENSAGE>\n");
		exit (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0))
	{
		ft_printf("PID Invalid\n");
		exit(1);
	}
	send_char(argv[2], pid);
	send_char("\0", pid);
}
