/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:12:00 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/01 18:36:27 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen(s);
	ch = (char)c;
	while (i >= 0)
	{
		if (s[i] == ch)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s = "Hello";
	int			ch;
	char		*str;

	ch = 'l';
	str = ft_strrchr(s, ch);
	if (str != NULL)
		printf("%s\n", str);
	else
		printf("caracter nao encontrado\n");
}
*/