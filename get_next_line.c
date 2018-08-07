/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:49:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/07 08:51:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_array(char *buf, char **array)
{
	array = ft_strsplit(buf, '\n');
}

int		get_next_line(const int fd, char **line)
{
	static char	**array;

	array = NULL;
	if (array == NULL || ft_strlen(array) == 1)
	{
		READ;
		if (array == NULL)
			array = ft_strsplit(buf, '\n');
		else if (ft_strlen(array) == 1)
		{
			tmp = array[0];
			array = ft_strsplit(buf, '\n');
			array[0] = ft_strjoin(tmp, array[0]);
		}
		get_next_line(fd, line);
	}
	else if (ft_strlen(array) > 1)
	{
		line = ft_strdup(array[0]);
		ft_strdel(array[0]);
		array = array + 1;
		return (1);
	}
	return (0);
}

// add failing conditions
// add freeing of all memory
// replace pseudo-code
