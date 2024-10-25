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

#include "cfiles/libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*sub;
	unsigned int	stringlen;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	stringlen = ft_strlen(s);
	if (start > stringlen)
		return (malloc(0));
	sub = malloc (stringlen + 1);
	while (s[start] && (i < len))
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}

int	r_count_sep(char *s, char sep)
{ 
	int	i;
	int	count;

	count = 0;
	i = 1;
	while (s[i])
	{
		if (s[i] == sep && s[i + 1] != '\0' && s[i + 1] != sep)
			count++;
		i++;
	}
	return (count);
}

void	ft_free(char	**s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	return ;
}

char	**fill(const char *s, char **result, int r, int j, int i, char c)
{
	while (s[i])
	{
		if (s[i] == c)
		{
			result[r] = ft_substr(s, j, i - j);
			if (result[r] == NULL)
			{
				ft_free(result);
				return (NULL);
			}
			j = i + 1;
			r++;
		}
		i++;
	}
	result[r] = ft_substr(s, j, i - j);
	if (result[r] == NULL)
	{
		ft_free(result);
		return (NULL);
	}
	r++;
	result[r] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		r;
	char	**result;

	i = 0;
	j = 0;
	r = 0;
	result = NULL;
	result = malloc(8 * (int)(r_count_sep) + 1);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	result = fill(s, result, r, j, i, c);
	return (result);
}

int	main()
{
	char	*buff = "hello world! eu sou o renato";
	char buff2 = ' ';
	char **array = ft_split(buff, buff2);
	int i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
	  	i++;
	}
	ft_free(array);
}	
