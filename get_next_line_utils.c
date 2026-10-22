/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:17:18 by basil42           #+#    #+#             */
/*   Updated: 2026/10/22 17:09:33 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*append_node(t_list **head, t_list *tail, char *line, size_t len)
{
	t_list	*node;

	node = NULL;
	if (head && line)
		node = malloc(sizeof(t_list));
	if (!node)
	{
		free(line);
		return (NULL);
	}
	node->line = line;
	node->line_len = len;
	node->new_line_flag = -1;
	node->next = NULL;
	if (!*head)
		*head = node;
	else
		tail->next = node;
	return (node);
}

int	has_newline(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	store_chunk(t_list **head, t_list **tail, int fd)
{
	ssize_t	n;
	t_list	*node;
	char	*chunk;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (-1);
	n = read(fd, chunk, BUFFER_SIZE);
	if (n <= 0)
	{
		free(chunk);
		return ((int)n);
	}
	chunk[n] = '\0';
	node = append_node(head, *tail, chunk, n);
	if (!node)
		return (-1);
	node->new_line_flag = has_newline(chunk, n);
	*tail = node;
	return (1);
}

int	read_and_store(t_list **head, int fd)
{
	t_list	*tail;
	int		status;

	tail = *head;
	while (tail && tail->next)
		tail = tail->next;
	status = 1;
	while (status > 0 && (!tail || (tail->new_line_flag == -1)))
		status = store_chunk(head, &tail, fd);
	if (status < 0)
	{
		free_lst(head, 1);
		return (0);
	}
	return (1);
}

t_list	*free_lst(t_list **head, int all)
{
	t_list	*node;
	t_list	*temp;

	if (!head)
		return (NULL);
	node = *head;
	while (node)
	{
		if (!all && node->new_line_flag != -1)
			return	(node);
		temp = node;
		node = node->next;
		free(temp->line);
		free(temp);
	}
	*head = node;
	return (NULL);
}
