/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:11:14 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/07 16:15:13 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc((sizeof(char)) * total_size);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, total_size);
	ft_strlcat(ptr, s2, total_size);
	return (ptr);
}
/*
int	main(void){
	char s1 [] = "Alen";
	char s2 [] = "tejo";
	char *resultado = ft_strjoin(s1, s2);
	printf("String concatenada: %s", resultado);
}
	*/