/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 07:40:39 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/25 02:29:08 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	c;
	size_t	j;

	j = 0;
	src_len = ft_strlen(src);
	if (!dst && !dstsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	c = dst_len;
	while (src[j] && j < dstsize - dst_len - 1)
	{
		dst[c++] = src[j++];
	}
	dst[c] = '\0';
	return (dst_len + src_len);
}
