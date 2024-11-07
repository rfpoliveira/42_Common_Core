/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_putpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:15:50 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/07 17:33:17 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putpointer(unsigned int n)
{
	unsigned int digit;

	if (n > 9)
	{
		r_putpointer(n / 10);
		r_putpointer(n % 10);
	}
	else
	{
		if (n < 10)
			digit = n + '0';
		else if (n == 'x')
			write (1, 'x', 1);
		else
			digit = n + 'a' - 10;
		write(1, digit, 1);
	}
	return (8);
}
