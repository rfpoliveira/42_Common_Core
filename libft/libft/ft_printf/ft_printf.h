/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:52 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/06 16:47:43 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	r_putnbr(int n);
int	r_put_hex(unsigned int n, char c);
int	r_putstr(char *s);
int	r_putunsig(unsigned int n);
int	r_put_ptr(unsigned long long n);

#endif
