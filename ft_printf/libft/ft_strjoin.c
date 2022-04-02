/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:26:26 by hbostan           #+#    #+#             */
/*   Updated: 2022/02/15 17:59:30 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ss;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ss = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ss == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		ss[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		ss[i] = *s2++;
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
