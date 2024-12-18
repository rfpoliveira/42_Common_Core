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

/*==============================================================================#
#                                 Libraries                                     #
#==============================================================================*/

# include "libft/libft.h"

/*==============================================================================#
#                                 Structs                                       #
#==============================================================================*/

typedef struct s_node
{
	int			  numb;
	int			  index;
	struct s_node *next;
	struct s_node *prev;
}				  t_node;

/*==============================================================================#
#                                 Functions                                     #
#==============================================================================*/

/*	parsing */
int		check_arg(char *n);
int		parsing(char **mtx, int argc);

/*	utils */
long	ft_atol(char *str);

/* handling lists */
t_node	*ft_list_ini(char **argv);
t_node	*go_first_node(t_node *lst);
t_node	*go_last_node(t_node *lst);
void	node_add_back(t_node **lst, t_node *new);
t_node	*new_node(int content, int index);

/* sorting functions */
void	swap(t_node **lst);
void	push(t_node **a, t_node **b);
void	rotate(t_node **a);
void	rev_rotate(t_node **a);

/*select movement*/
void  mov_swap(t_node **a, t_node **b, char *c);
void  mov_push(t_node **a, t_node **b, char *c);
void  mov_rot(t_node **a, t_node **b, char *c);
void  mov_rev_rot(t_node **a, t_node **b, char *c);

#endif
