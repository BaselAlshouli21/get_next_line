/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:17:18 by basil42           #+#    #+#             */
/*   Updated: 2026/10/14 15:34:34 by basil42          ###   ########.fr       */
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
	node->next = NULL;
	if (!*head)
		*head = node;
	else
		tail->next = node;
	return (node);
}
