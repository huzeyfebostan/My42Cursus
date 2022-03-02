/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:20:23 by hbostan           #+#    #+#             */
/*   Updated: 2022/02/16 16:46:24 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_control(char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ss;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	while (s1[j] && is_control(s1[j], set))
		j++;
	k = ft_strlen(s1);
	while (k > j && is_control(s1[k - 1], set))
		k--;
	ss = malloc(sizeof(char) * (k - j + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (j < k)
		ss[i++] = s1[j++];
	ss[i] = '\0';
	return (ss);
}
