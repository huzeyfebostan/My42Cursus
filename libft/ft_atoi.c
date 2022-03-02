/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:17:44 by hbostan           #+#    #+#             */
/*   Updated: 2022/02/16 16:44:34 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	control(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const	char *nptr)
{
	int				final;
	int				neg;
	int				counter;

	final = 0;
	neg = 1;
	while (control(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	counter = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		final = (final * 10) + *nptr++ - '0';
		counter++;
	}
	if (counter > 10 && neg == 1)
		return (-1);
	else if (counter > 10)
		return (0);
	return (final * neg);
}
