/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:17:11 by basil42           #+#    #+#             */
/*   Updated: 2026/10/16 18:13:08 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_list
{
	char			*line;
	size_t			line_len;
	struct s_list	*next;
	int				new_line_flag;
}	t_list;

t_list	*append_node(t_list **head, t_list *tail, char *line, size_t len);

char	*get_next_line(int fd);

#endif