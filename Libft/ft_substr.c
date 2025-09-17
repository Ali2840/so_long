/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:12:11 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/05 18:26:47 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*ss;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	ss = malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	while (i < len)
	{
		ss[i] = s[i + start];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
/*
int	main(void){
	char *str = "Hello!";
	char *sub = ft_substr(str, 30, 5);
	printf("%s\n", sub);
	free(sub);
}
*/