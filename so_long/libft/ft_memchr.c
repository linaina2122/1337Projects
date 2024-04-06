/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:29:21 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/12 00:17:08 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	p;
	unsigned char	*str;
	size_t			i;

	i = 0;
	while (n > i)
	{
		p = (unsigned char)c;
		str = (unsigned char *)s;
		if (str[i] == p)
			return (str + i);
		i++;
	}
	return (0);
}
