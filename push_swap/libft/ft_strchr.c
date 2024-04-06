/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:13:33 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/22 06:26:40 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	x;
	char	*str;

	x = (char)c;
	str = (char *)s;
	i = 0;
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
