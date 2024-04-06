/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:06:36 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 04:06:41 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**my_envp(char **envp)
{
	char	**my_envp;
	int		i;
	char	**tmp;

	i = 0;
	my_envp = (char **)ft_calloc(double_pointer_len(envp) + 1, sizeof(char *));
	while (envp[i])
	{
		my_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	my_envp[i] = NULL;
	tmp = ft_split("salam=OLDPWD", '=');
	free_double_char(tmp, 0);
	return (my_envp);
}
