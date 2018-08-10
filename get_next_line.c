/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:49:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/09 11:38:06 by pdeguing         ###   ########.fr       */
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
	char	*buf;
	char	*tmp;
	char	*full_line;
	int		ret;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buf)
	{
//		ft_putendl("->-> buf malloc failed");
		return (NULL);
	}
	if (read(fd, buf, 0) < 0)
	{
//		ft_putendl("->-> read returns (-1)");
		return (NULL);
	}
	full_line = ft_strnew(1);
	if (!full_line)
	{
//		ft_putendl("->-> full_line ft_strnew failed");
		return (NULL);
	}
//	ft_putendl("->-> about to enter while loop");
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		tmp = full_line;
		full_line = ft_strjoin(tmp, buf);
//		ft_putendl("->->-> full_line current value is:");
//		ft_putendl(full_line);
		ft_strdel(&tmp);
		if (ft_strchr(buf, '\n'))
		{
//			ft_putendl("->->-> break because buf contains '\\n'");
			break;
		}
	}
//	ft_putendl("->-> while loop ended");
	ft_strdel(&buf);
	return (full_line);
}

int				get_index_newline(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
//	ft_putstr("->-> returning i = ");
//	ft_putnbr(i);
//	ft_putchar('\n');
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*line_list;
	t_list			*current;
	char			*buf;
	char			*tmp;
	int				index_newline;

	if (fd < 0 || line == NULL)
		return (-1);
//	ft_putendl("-> passed input check");
//	ft_putendl("-> calling get_current_node");
	current = get_current_node(fd, &line_list);
//	ft_putendl("-> current assignated");
//	if (!current)
//		ft_putendl("-> current is NULL before create_new_node");
	if (!current)
	{
//		ft_putendl("-> calling create_new_node");
		current = create_new_node(fd, &line_list);
	}
//	ft_putendl("-> current has been created with create_new_node");
//	if (!current)
//		ft_putendl("-> current is NULL after create_new_node");
	buf = ft_strnew(1);
	if (!ft_strchr(current->content, '\n'))
	{
//		ft_putendl("-> calling read_until_newline");
		buf = read_until_newline(fd);
//		ft_putendl("-> read_until_newline returns:");
//		ft_putendl(buf);
	}
	if (!buf)
	{
//		ft_putendl("-> return (-1)");
		return (-1);
	}
	if (!ft_strlen(buf) && !ft_strlen(current->content))
	{
//		ft_putendl("-> return (0)");
		return (0);
	}
	current->content = ft_strjoin(current->content, buf);
	ft_strdel(&buf);
//	ft_putendl("-> calling get_index_newline");
	index_newline = get_index_newline(current->content); /* MIGHT NEED CONDITION IF INDEX == STRLEN */
	*line = ft_strsub(current->content, 0, index_newline);
//	if (line == NULL)
//		ft_putendl("-> line is NULL after assignation");
//	ft_putendl("-> *line has been set to:");
//	ft_putendl(*line);
	tmp = ft_strdup(current->content);
//	ft_putendl("-> tmp has been set to current->content");
	ft_strdel((char **)&current->content);
//	ft_putendl("-> current>-content has been deleted");
	current->content = ft_strsub(tmp, index_newline + 1, ft_strlen(tmp) - index_newline - 1);
//	ft_putendl("-> current->content has been set to next line");
	ft_strdel(&tmp);
//	ft_putendl("-> tmp has been deleted");
//	ft_putendl("-> return (1)");
	return (1);
}
