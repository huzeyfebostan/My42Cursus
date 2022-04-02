/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:47:39 by hbostan           #+#    #+#             */
/*   Updated: 2022/02/15 18:44:44 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = ft_strlen(needle);
	while (haystack[i] && i < len && j < l)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && haystack[i + j])
			j++;
		i++;
	}
	if (l == 0)
		return ((char *) haystack);
	if (j == l)
		return ((char *) haystack + i - 1);
	return (NULL);
}
