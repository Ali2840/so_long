/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:07:06 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/07 17:48:37 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;

	if (size && nmemb >= (size_t) - 1 / size)
		return (NULL);
	len = nmemb * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}

/*
int	main(void)
{
	int	*arr;

	arr = (int *)ft_calloc(5, sizeof(int));
	if (arr)
	{
		for (int i = 0; i < 5; i++)
			printf("%d ", arr[i]);  // deve imprimir: 0 0 0 0 0
		printf("\n");
	}
	else
		printf("Falha na alocação!\n");
	free(arr);
}
*/