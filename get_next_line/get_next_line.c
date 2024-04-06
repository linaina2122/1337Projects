/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:30:06 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/15 22:59:57 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

int	ft_find(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_free(char **keep)
{
	free (*keep);
	*keep = NULL;
	return (NULL);
}

char	*ft_keep(char **keep)
{
	char	*line;
	char	*tmp;
	int		n;

	if (!**keep)
		ft_free(keep);
	n = ft_find(*keep);
	if (n != -1)
	{
		line = ft_substr(*keep, 0, n + 1);
		tmp = ft_substr(*keep, n + 1, ft_strlen(*keep + n + 1));
		free(*keep);
		*keep = tmp;
		return (line);
	}
	else if (n == -1)
	{
		line = ft_substr(*keep, 0, ft_strlen(*keep));
		free(*keep);
		*keep = NULL;
		return (line);
	}
	return (*keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*buffer;
	int			rd;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (rd > 0 && !ft_strchr(keep, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		keep = ft_strjoin(keep, buffer);
	}
	free(buffer);
	return (ft_keep(&keep));
}
