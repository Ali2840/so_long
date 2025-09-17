/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:02:36 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/14 18:41:25 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_index;
	int		end_index;
	int		total_len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	end_index = ft_strlen(s1) - 1;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	while (end_index > start_index && ft_strrchr(set, s1[end_index]))
		end_index--;
	total_len = end_index - start_index + 1;
	trim = ft_substr(s1, start_index, total_len);
	return (trim);
}

/*
int	main(void)
{
	char	s1[] = "!     Hellloo   !!!!!";
	char	set[] = " !";
	char	*str;

	str = ft_strtrim(s1, set);
	printf("%s\n", str);
	free(str);
}
*/