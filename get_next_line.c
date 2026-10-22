/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:17:15 by basil42           #+#    #+#             */
/*   Updated: 2026/10/22 16:09:39 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	line_length(t_list **head)
{
	t_list	*node;
	size_t	length;
	size_t	line_idx;

	if (!head)
		return (0);
	node = *head;
	length = 0;
	while (node)
	{
		line_idx = 0;
		while (node->new_line_flag && node->line[line_idx])
		{
			if (node->line[line_idx++] == '\n')
				return (++length);
			length++;
		}
		length += node->line_len;
		node = node->next;
	}
	return (length);
}

size_t	nodelcat(char *str, t_list *node)
{
	size_t	i;

	i = 0;
	while (i < node->line_len && node->line[i])
	{
		str[i] = node->line[i];
		i++;
	}
	return (i);
}

char	*build_line(t_list **head, size_t length)
{
	size_t	str_len;
	t_list	*node;
	char	*str;

	if (!head || !*head)
		return (NULL);
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	node = *head;
	str_len = 0;
	while (node)
	{
		str_len += nodelcat(&str[str_len], node);
		node = node->next;
	}
	str[str_len] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*tail;
	char			*line;
}
