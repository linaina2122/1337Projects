/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:23:53 by hcharef           #+#    #+#             */
/*   Updated: 2022/05/16 01:44:22 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;
	a = 0;
	while ((s1[a] || s2[a]))
	{
		if (s1[a] != s2[a])
			return (((unsigned char)s1[a] - (unsigned char)s2[a]));
		a++;
	}
	return (0);
}
