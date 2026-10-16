/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:17:15 by basil42           #+#    #+#             */
/*   Updated: 2026/10/16 18:44:05 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	line_length(t_list	**head)
{
	t_list	*node;
	size_t	length;

	node = *head;
	length = 0;
	while(node)
	{
		length += node->line_len;
		node = node->next;
	}
	return (length);
}

char	*get_next_line(int fd)
{
	t_list	*head;
	t_list	*tail;
	char	*line;
}
