/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:14:21 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 18:52:06 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	print_dir(t_cmd *arg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg->after_expand[0], 2);
	ft_putstr_fd(": is a directory", 2);
	write(2, "\n", 1);
	g_exit_code = 126;
	return (0);
}
