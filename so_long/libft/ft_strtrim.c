/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:40:44 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/14 00:31:26 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_check(const char *str, char s)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	int		n;
	char	*p;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (0);
	n = ft_strlen(s1) - 1;
	while (s1[i] && ft_check(set, s1[i]) == 1)
		i++;
	while (i < n && ft_check(set, s1[n]) == 1)
		n--;
	p = malloc((n - i) * sizeof(char) + 2);
	if (!p)
		return (NULL);
	while (s1[i] && i <= n)
	{
		p[k] = s1[i];
		i++;
		k++;
	}
	p[k] = '\0';
	return (p);
}
