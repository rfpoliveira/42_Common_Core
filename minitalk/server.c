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

void  handler(int numb)
{
	int bin;

	bin = 0;
	if (numb == SIGUSR1)
		
	else if (numb == SIGUSR2)
		;
}

int main(void)
{
	struct sigaction action;

	ft_printf("The PID is: %d", getpid());
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while(42)
		pause();
}
