/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:13:09 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/24 05:35:41 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*c;
	const char	*d;

	c = dst;
	d = src;
	count = 0;
	if (src == dst)
		return (dst);
	if (!d && !c)
		return (0);
	while (count < n)
	{
		c[count] = d[count];
		count++;
	}
	return (dst);
}
