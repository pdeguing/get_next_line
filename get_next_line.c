/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:49:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/10 08:29:00 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_current_node(const int fd, t_list **line_list)
{
	t_list		*tmp;

	tmp = *line_list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_list	*create_new_node(int fd, t_list **line_list)
{
	t_list	*new;

	new = ft_lstnew("\0", fd);
	ft_lstadd(line_list, new);
	return (new);
}

char			*read_until_newline(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*stack;
	int		ret;

	if (read(fd, buf, 0) < 0)
		return (NULL);
	stack = ft_strnew(1);
	if (!stack)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(stack, buf);
		ft_strdel(&stack);
		stack = tmp;
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (stack);
}

int				get_index_newline(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*line_list;
	t_list			*current;
	char			*buffer;
	char			*tmp;
	int				index_newline;

	if (fd < 0 || line == NULL)
		return (-1);
	current = get_current_node(fd, &line_list);
	if (!current)
		current = create_new_node(fd, &line_list);
	if (!ft_strchr(current->content, '\n'))
		buffer = read_until_newline(fd);
	else
		buffer = ft_strnew(1);
	if (!buffer)
		return (-1);
	if (!ft_strlen(buffer) && !ft_strlen(current->content))
		return (0);
	tmp = current->content;
	current->content = ft_strjoin(tmp, buffer);
	if (tmp)
		ft_strdel(&tmp);
	if (buffer)
		ft_strdel(&buffer);
	index_newline = get_index_newline(current->content);
	*line = ft_strsub(current->content, 0, index_newline);
	tmp = current->content;
	current->content = ft_strsub(tmp, index_newline + 1, ft_strlen(tmp) - index_newline - 1);
	if (tmp)
		ft_strdel(&tmp);
	return (1);
}
