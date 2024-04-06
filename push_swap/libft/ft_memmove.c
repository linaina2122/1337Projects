/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:04:05 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/12 00:24:59 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*srce;

	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	if (!dest && !srce)
		return (0);
	if (dest > srce)
	{
		while (len > 0)
		{
			dest[len - 1] = srce[len - 1];
			len--;
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
