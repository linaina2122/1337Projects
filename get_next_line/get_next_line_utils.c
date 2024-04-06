/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:11:15 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/16 00:20:39 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	int		x;

	x = (char)c;
	i = 0;
	if (!str)
		return (NULL);
	if (!x)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while ((char)s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while ((char)s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	free(s1);
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		p = malloc(sizeof(char) * ft_strlen(s) + 1);
		*p = '\0';
		return (p);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	while (s[i] && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
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
	p[i] = '\0';
	return (p);
}
