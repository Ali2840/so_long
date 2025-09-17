/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:07:10 by gocaetan          #+#    #+#             */
/*   Updated: 2025/04/29 16:07:11 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (c);
	}
	return (0);
}
/*
int	main(void){
	int a = 'a';
	if(ft_isalnum(a)){
		printf("%d is alphanumeric\n", a);
	}
	else{
		printf("%d is not alphanumeric\n", a);
	}
	return (0);
}
*/