/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:11:49 by gocaetan          #+#    #+#             */
/*   Updated: 2025/04/29 18:02:16 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		}
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	int		i;
	char	s1[] = "bora";
	char	s2[] = "borA bora";

	i = ft_strncmp(s1, s2, 3);
	printf("%d\n", i);
}
	*/