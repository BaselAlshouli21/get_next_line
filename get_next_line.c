/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:17:15 by basil42           #+#    #+#             */
/*   Updated: 2026/10/22 17:17:14 by basil42          ###   ########.fr       */
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
		while (node->new_line_flag != -1 && node->line[line_idx])
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
		if (node->line[i] == '\n')
		{
			str[i] = node->line[i];
			i++;
			return (i);
		}
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

char	*strmove_newline(t_list *node, char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dest[n] = src[n];
	}
	dest[node->line_len - (node->new_line_flag + 1)] = '\0';
	node->line_len = node->line_len - (node->new_line_flag + 1);
	node->new_line_flag = has_newline(dest, node->line_len);
	return (dest);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	size_t			line_size;
	char			*line;

	if (!read_and_store(&head, fd))
		return (NULL);
	line_size = line_length(&head);
	line = build_line(&head, line_size);
	if (!line)
	{
		head = free_lst(&head, 1);
		return (NULL);
	}
	head = free_lst(&head, 0);
	if (head)
		head->line = strmove_newline(head, head->line, &head->line[head->new_line_flag + 1], head->line_len);
	return (line);
}
