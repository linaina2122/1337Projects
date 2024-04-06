/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:14:50 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 06:40:30 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	x;

	str = (char *)s;
	x = c;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == x)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
