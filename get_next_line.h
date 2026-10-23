/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:17:11 by basil42           #+#    #+#             */
/*   Updated: 2026/10/22 17:22:11 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

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
t_list	*free_lst(t_list **head, int all);

size_t	nodelcat(char *str, t_list *node);
size_t	line_length(t_list **head);

char	*strmove_newline(t_list *node, char *dest, const char *src, size_t n);
char	*build_line(t_list **head, size_t length);
char	*get_next_line(int fd);

int		store_chunk(t_list **head, t_list **tail, int fd);
int		read_and_store(t_list **head, int fd);
int		has_newline(char *line, size_t len);

#endif