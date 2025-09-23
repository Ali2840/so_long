/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:11:20 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/07 18:08:06 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	dest[30] = "42 ";
	char	src[30] = "lisbon";
	size_t	i;
	size_t	size;

	size = 10;
	i = ft_strlcat(dest, src, size);
	printf("%zu\n", i);
	printf("%s\n", dest);
}
*/