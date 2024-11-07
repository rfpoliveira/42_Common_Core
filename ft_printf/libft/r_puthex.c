/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_puthex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:29:52 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/07 17:38:08 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	count_digits(unsigned int n)
{
	int		count;

	count = 1;
	while (i > 9)
	{
		if (n % 10 <= 9)
			n /= 10;
		else
			n /= 16;
		count++;
	}
	return (count);
}

int r_puthex(unsigned int, char c)
{
	unsigned int digit;

	if (n > 9)
	{
		r_puthex(n / 10);
		r_puthex(n % 10);
	}
	else
	{
		if (n < 10)
			digit = n + '0';
		else if (n == 'x')
			write (1, 'x', 1);
		else if (c == 'x')
			digit = n + 'a' - 10;
		else if (c == 'X')
			digit = n + 'A' - 10;
		write(1, digit, 1);
	}

	return ();
}
