/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:51:08 by basil42           #+#    #+#             */
/*   Updated: 2026/10/22 16:54:42 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main()
{
	int		fd;
	char	*line;
	int		line_num;

	// Open your test file (make sure test.txt exists in the same folder)
	// You can also change "test.txt" to 0 to test standard input (stdin)
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open test.txt");
		return (1);
	}

	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line [%d] -> %s", line_num, line);
		free(line);
		line_num++;
	}

	// Optional: call once more after EOF to verify it safely returns NULL
	line = get_next_line(fd);
	if (line == NULL)
		printf("\n[EOF reached successfully, returned NULL]\n");
	else
	{
		printf("\n[Warning: returned non-NULL after EOF]: %s\n", line);
		free(line);
	}

	close(fd);
	return (0);
}