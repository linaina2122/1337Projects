/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:33:36 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/21 15:02:40 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	int	ft_check(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		j++;
		i++;
	}
	return (j);
}

static	char	*ft_print(char *str, char c)
{
	int		i;
	char	*s;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] != c && str[i])
		i++;
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *s, char c)
{
	char	**x;
	int		check;
	int		count;

	if (!s)
		return (NULL);
	check = ft_check(s, c);
	x = malloc((check + 1) * sizeof(char *));
	if (!x)
		return (NULL);
	count = 0;
	while (count < check)
	{
		while (*s && *s == c)
			s++;
		x[count] = ft_print(s, c);
		while (*s && *s != c)
			s++;
		count++;
	}
	x[count] = NULL;
	return (x);
}
