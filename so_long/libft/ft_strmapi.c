/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 04:28:54 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/19 03:26:11 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s1[i] = (*f)(i, s1[i]);
		i++;
	}
	return (s1);
}
