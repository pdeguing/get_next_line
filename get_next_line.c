/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:49:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/18 07:15:29 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*create_new_node(int fd, t_list **line_list)
{
	t_list			*new;

	new = ft_lstnew("\0", fd);
	ft_lstadd(line_list, new);
	return (new);
}

static t_list		*get_current_node(const int fd, t_list **line_list)
{
	t_list			*tmp;

	tmp = *line_list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (create_new_node(fd, line_list));
}

char				*readnl(char *content, int fd)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	char			*stack;
	int				ret;

	stack = ft_strnew(1);
	if (ft_strchr(content, '\n'))
		return (stack);
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (NULL);
	if (!stack)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(stack, buf);
		ft_strdel(&stack);
		stack = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stack);
}

int					get_index_newline(char *str)
{
	int				i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*line_list;
	t_list			*curr;
	char			*buffer;
	char			*tmp;
	int				i;

	!line_list ? (line_list = ft_lstnew("\0", fd)) : NULL;
	curr = get_current_node(fd, &line_list);
	if (!(buffer = readnl(curr->content, fd)) || line == NULL)
		return (-1);
	if (!ft_strlen(buffer) && !ft_strlen(curr->content))
		return (0);
	tmp = curr->content;
	curr->content = ft_strjoin(tmp, buffer);
	ft_strdel(&tmp);
	ft_strdel(&buffer);
	i = get_index_newline(curr->content);
	tmp = curr->content;
	*line = ft_strsub(tmp, 0, i);
	if (ft_strlen(tmp) != ft_strlen(*line))
		curr->content = ft_strsub(tmp, i + 1, ft_strlen(tmp) - i - 1);
	ft_strdel(&tmp);
	return (1);
}
