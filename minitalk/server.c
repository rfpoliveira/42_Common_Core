/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:36 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/08 16:07:54 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bin = 0;

void  handler(int numb)
{
	static int bits;
	static int byte;
	static	char* buff;
	char *buff2;

	if (numb == SIGUSR1)
		byte |= 1 << (7 - bits);
	else if (numb == SIGUSR2)
		byte &= ~(1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
			buff2 = malloc(2);
			buff2[0] = byte;
			buff2[1] = '\0';
			if (!buff)
				buff = ft_strdup(buff2);
			else
				buff = ft_strjoin(buff, buff2);
			free(buff2);
			write(1, &buff, 3);
	/*	else
		{
			len = ft_strlen(buff);
			write(1, &buff, len);
			free(buff);
		}	*/
		bits = 0;
		byte = 0;
	}
}

int main(void)
{
	struct sigaction action;
	pid_t pid;

	pid = getpid();
	if (pid == -1)
	{
		ft_printf("PID Invalid\n");
		exit (1);
	}
	ft_printf("The PID is: %d\n", getpid());
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while(42)
		pause();
}
