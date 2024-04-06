/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:06:04 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 03:55:39 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_error_cd(t_cmd *arg, int n)
{
	char	*str1;
	char	*str2;

	str1 = "minishell: ";
	if (n == 1)
	{
		str2 = "not a directory";
		ft_putstr_fd(str1, 2);
		ft_putstr_fd(arg->after_expand[0], 2);
		write(2, ": ", 2);
		ft_putstr_fd(arg->after_expand[1], 2);
		write(2, ": ", 2);
		ft_putstr_fd(str2, 2);
	}
	else
	{
		str2 = "No such file or directory";
		ft_putstr_fd(str1, 2);
		ft_putstr_fd(arg->after_expand[0], 2);
		write(2, ": ", 2);
		ft_putstr_fd(arg->after_expand[1], 2);
		write(2, ": ", 2);
		ft_putstr_fd(str2, 2);
	}
	write(2, "\n", 1);
}

void	print_error_unset(t_cmd *arg)
{
	char	*str1;
	char	*str2;

	str1 = "minishel: ";
	str2 = "not a valid identifier";
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(arg->after_expand[0], 2);
	write(2, ": ", 2);
	ft_putstr_fd(str2, 2);
	write(2, "\n", 1);
}

void	print_error_exit(t_cmd *arg)
{
	char	*str1;
	char	*str2;

	str1 = "minishel: ";
	str2 = "numeric argument required";
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(arg->after_expand[0], 2);
	write(2, ": ", 2);
	ft_putstr_fd(str2, 2);
	write(2, "\n", 1);
}

void	print_error_commands(t_cmd *arg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg->after_expand[0], 2);
	ft_putstr_fd(": command not found", 2);
	write(2, "\n", 1);
	g_exit_code = 127;
}

void	exit_errors(t_cmd *arg, int i)
{
	if (i == 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg->after_expand[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg->after_expand[1], 2);
		ft_putstr_fd(":  too many arguments", 2);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg->after_expand[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg->after_expand[1], 2);
		ft_putstr_fd(": numeric argument required", 2);
	}
	write(2, "\n", 1);
}
