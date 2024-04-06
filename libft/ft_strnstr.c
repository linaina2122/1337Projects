/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:56:10 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/24 21:21:28 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char*needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	o;

	i = 0;
	o = ft_strlen(needle);
	if (needle == NULL || needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && (needle[j] == haystack[i + j]) && len > j + i)
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
