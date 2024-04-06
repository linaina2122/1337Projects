/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:57:15 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/24 21:29:52 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		p = malloc(sizeof(char) * 1);
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
