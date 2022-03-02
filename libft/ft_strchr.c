/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:54:20 by hbostan           #+#    #+#             */
/*   Updated: 2022/02/15 18:39:59 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;
	char	c_tmp;

	j = ft_strlen(s);
	i = 0;
	c_tmp = (char)c;
	while (i <= j)
	{
		if (s[i] == c_tmp)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
