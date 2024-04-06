/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:30:06 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 11:13:51 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/uio.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"push_swap.h"

char	*get_next_line(int fd)
{
	char	line[5000000];
	int		i;

	ft_memset(line, 0, sizeof(line));
	i = 0;
	while (read(fd, &line[i], 1) > 0)
		if (line[i++] == '\n')
			break ;
	if (line[0])
		return (ft_strdup(line));
	else
		return (NULL);
}
