/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:07:00 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 04:07:59 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;
	int		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	i = 0;
	if (len < slen)
		p = (char *)ft_calloc(len + 1, sizeof(char));
	else
		p = (char *)ft_calloc(slen + 1, sizeof(char));
	if (!p)
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
