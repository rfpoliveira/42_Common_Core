/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:13:45 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/17 10:16:17 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

//libraries

# include "libft/libft.h"

//functions

int		check_arg(char *n);
int		parsing(char **mtx, int argc);
long	ft_atol(char *str);
t_list	*ft_list_ini(char **argv, int n);

#endif
