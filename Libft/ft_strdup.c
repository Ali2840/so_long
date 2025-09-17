/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:10:52 by gocaetan          #+#    #+#             */
/*   Updated: 2025/04/29 17:03:09 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;
	int		size;

	size = 0;
	while (s[size])
		size++;
	d = (char *)malloc((size + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
/*
int	main(void)
{
	char	*src;
	char	*copy;

	src = "Hello world";
	copy = ft_strdup(src);
	if (copy == NULL)
	{
		printf("Erro de alocacao de memoria.\n");
	}
	printf("String original: %s\n", src);
	printf("String duplicada: %s\n", copy);
	free(copy);
}
*/