/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:44:15 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/10 13:45:36 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(const char *s, char c)
{
	int	i;
	int	countword;

	i = 0;
	countword = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			countword++;
		i++;
	}
	return (countword);
}

static void	*allocate_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	if (!s || start >= end)
		return (NULL);
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**create_arr(char **bi_array, const char *s, char c)
{
	int	i;
	int	word_start;
	int	word_index;

	i = 0;
	word_index = 0;
	word_start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_start = i;
			while (s[i] && s[i] != c)
				i++;
			bi_array[word_index] = allocate_word(s, word_start, i);
			if (!bi_array[word_index])
				return (ft_free(bi_array, word_index));
			word_index++;
		}
		else
			i++;
	}
	return (bi_array);
}

char	**ft_split(char const *s, char c)
{
	char	**bi_array;

	if (!s)
		return (NULL);
	bi_array = ft_calloc(countword(s, c) + 1, sizeof(char *));
	if (!bi_array)
		return (NULL);
	bi_array = create_arr(bi_array, s, c);
	return (bi_array);
}
/*
int	main(void)
{
	char const	*s;
	char		split;
	char		**split_str;
	int			i;

	s = "GLORIOSO SLB";
	split = ' ';
	split_str = ft_split(s, split);
	i = 0;
	while(split_str[i])
	{
	printf("%s\n", split_str[i]);
	i++;
	}
}
	*/