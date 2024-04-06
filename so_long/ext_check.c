/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:47:22 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 20:44:39 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_long.h"

int	ft_extension_check(char **argv)
{
	char	*str;

	str = ft_strrchr(argv[1], '.');
	if (!str)
		return (1);
	if (ft_strcmp(str, ".ber") == 1)
		return (1);
	return (0);
}

int	ft_close(void)
{
	exit (1);
}
