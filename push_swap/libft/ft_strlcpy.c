/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 07:00:01 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/13 16:43:30 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (src[i])
	{
		i++;
	}
	if (dstsize == 0)
		return (i);
	while (src[n] && n < dstsize - 1 && dstsize != 0)
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (i);
}
