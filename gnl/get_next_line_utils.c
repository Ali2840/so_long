/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:15:26 by gocaetan          #+#    #+#             */
/*   Updated: 2025/09/17 12:08:37 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	linelen(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

char	*strjoin_and_free(char *line, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc((sizeof(char)) * (linelen(line) + linelen(buffer) + 1));
	if (!new_str)
		return (free(line), NULL);
	while (line && line[i])
	{
		new_str[i] = line[i];
		i++;
	}
	free(line);
	while (buffer[j])
	{
		new_str[i + j] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

void	ft_bufmove(char *buf)
{
	int	j;
	int	i;

	j = 0;
	i = linelen(buf);
	while (buf[i] && i < BUFFER_SIZE)
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

char	*ft_strchar(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == ch)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (ch == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
