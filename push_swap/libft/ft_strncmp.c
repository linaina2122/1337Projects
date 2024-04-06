/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:23:53 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/17 22:01:57 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2)
{

	while ((s1[a] || s2[a]))
	{
		if (s1[a] != s2[a])
			return (((unsigned char)s1[a] - (unsigned char)s2[a]));
		a++;
	}
	return (0);
}
