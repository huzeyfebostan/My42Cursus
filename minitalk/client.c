/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:05:27 by hbostan           #+#    #+#             */
/*   Updated: 2022/07/25 15:10:15 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	control(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_atoi(const	char *nptr)
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

static void	ft_send_message(pid_t pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		bit = 8;
		while (bit--)
		{
			if (str[i] >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("En Az 2 Argüman girilmeli !!\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
	ft_send_message(pid, "\n");
	return (0);
}
