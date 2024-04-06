/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 03:34:21 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/25 04:14:53 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exit_imp(t_cmd *arg, int i)
{
	long	nb;
	int		index;

	index = 1;
	if (i == 0)
		printf("exit\n");
	if (arg->after_expand && arg->after_expand[1] == NULL)
		exit(g_exit_code);
	nb = my_atoi(arg->after_expand[1]);
	if (more_than_arg(arg))
		return ;
	if (check_long(arg->after_expand[1]) == 1)
	{
		print_error_exit(arg);
		g_exit_code = 255;
		exit(g_exit_code);
	}
	if (one_arg(arg) == 1)
	{
		print_error_exit(arg);
		g_exit_code = 255;
		exit(g_exit_code);
	}
	else
		exit((unsigned char)nb);
}
