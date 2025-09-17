/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:43:37 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/01 18:34:31 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		while (big[j + i] == little[i] && little[i] != '\0' && (j + i) < len)
			i++;
		if (little[i] == '\0')
			return ((char *)&big[j]);
		j++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "Welcome";
	char	string2[] = "co";
	size_t	n;
	char	*res;

	n = 5;
	res = ft_strnstr(str, string2, n);
	if (res)
		printf("%s\n", res);
	else
		printf("nao encontrado\n");
}
*/