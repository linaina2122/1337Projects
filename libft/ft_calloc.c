/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:41:58 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/24 22:18:24 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*p;

	p = malloc (count * size);
	if (!p)
		return (NULL);
	ft_bzero (p, count * size);
	return (p);
}
