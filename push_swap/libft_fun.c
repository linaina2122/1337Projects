/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:41:03 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 10:22:10 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *)b;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] || s2[a]))
	{
		if (s1[a] != s2[a])
			return (((unsigned char)s1[a] - (unsigned char)s2[a]));
		a++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc((ft_strlen(s1)) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
