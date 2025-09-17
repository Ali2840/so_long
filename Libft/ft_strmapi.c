/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:11:37 by gocaetan          #+#    #+#             */
/*   Updated: 2025/04/29 16:11:39 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	to_upperifeven(unsigned int c, char a)
{
	if (c % 2 == 0)
		return (ft_toupper(a));
	return (ft_tolower(a));
}
	*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_len;
	char	*new_str;
	int		i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = malloc(sizeof(char) * s_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
int	main(void){
	char *str = "aaabbbcccc";
	char *mapped = ft_strmapi(str, to_upperifeven);
	printf("%s\n", mapped);
	free(mapped);
}
	*/