/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:42:47 by waboutzo          #+#    #+#             */
/*   Updated: 2022/11/17 22:44:50 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	printf_error(char *p, char *str, char *s)
{
	if (p)
		write(2, p, ft_strlen(p));
	if (str)
		write(2, str, ft_strlen(str));
	if (s)
		write(2, s, ft_strlen(s));
}
