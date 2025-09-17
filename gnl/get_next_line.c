/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:15:30 by gocaetan          #+#    #+#             */
/*   Updated: 2025/09/17 12:06:19 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	line = NULL;
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchar(line, '\n'))
	{
		if (buffer[0] == '\0')
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes < 0)
				return (free(line), NULL);
			buffer[bytes] = '\0';
			if (bytes == 0)
				return (line);
		}
		line = strjoin_and_free(line, buffer);
		ft_bufmove(buffer);
	}
	return (line);
}
