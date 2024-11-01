/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:32:56 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/25 11:13:40 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	r_count_sep(const char *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[i] != sep && s[i] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == sep && s[i + 1] != '\0' && s[i + 1] != sep)
			count++;
		i++;
	}
	return (count);
}

void	ft_free(char	**s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	return ;
}

char	**fill(const char *s, char **res, char c)
{
	int		j;
	int		r;
	int		i;

	i = -1;
	j = 0;
	r = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
				j++;
			}
			res[r] = ft_substr(s, i - j, j);
			r++;
			j = 0;
		}
		if (s[i] == '\0')
			break ;
	}
	res[r] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;

	result = malloc(sizeof (char *) * (r_count_sep(s, c) + 1));
	if (!result)
		return (NULL);
	result = fill(s, result, c);
	i = 0;
	while (result[i])
	{
		if (!result[i])
		{
			ft_free(result, c);
			return (NULL);
		}
		i++;
	}
	return (result);
}
/*
int	main()
{
	char	*buff = "babnnas";
	char buff2 = '0';
	char **array = ft_split(buff, buff2);
	int i = 0;
	printf("%i\n", r_count_sep(buff,buff2));
	while (array[i])
	{
		printf("%s\n", array[i]);
	  	i++;
	}
	ft_free(array, r_count_sep(buff, buff2));
	free(array);
}*/
