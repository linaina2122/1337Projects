/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:59:28 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/25 04:15:35 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_buils(t_cmd *cmds, char ***env, int i)
{
	if (ft_strcmp(cmds->after_expand[0], "echo") == 0)
		echo_imp (cmds);
	else if (ft_strcmp(cmds->after_expand[0], "pwd") == 0)
		pwd_imp (env);
	else if (ft_strcmp(cmds->after_expand[0], "env") == 0)
		env_imp (env);
	else if (ft_strcmp(cmds->after_expand[0], "cd") == 0)
		cd_imp (cmds, env);
	else if (ft_strcmp(cmds->after_expand[0], "unset") == 0)
		unset_imp (cmds, env);
	else if (ft_strcmp(cmds->after_expand[0], "exit") == 0)
		exit_imp (cmds, i);
	else if (ft_strcmp(cmds->after_expand[0], "export") == 0)
		my_export (env, cmds->after_expand);
	else
		return (1);
	return (0);
}
