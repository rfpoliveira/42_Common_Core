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
	int			  first;
	int			  cheap;
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
int		node_count(t_node *a);
void	sort3(t_node **a, t_node *b);
int		ft_is_sort(t_node *a);
void	is_cheap(t_node **a);

/* handling lists */
t_node	*ft_list_ini(char **argv);
t_node	*go_first_node(t_node *lst);
void	node_add_back(t_node **lst, t_node **new);
t_node	*new_node(int content);

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

/* algoritm and memory */
void  algoritm(t_node **a, t_node **b);
void  free_lst(t_node **a);

#endif
