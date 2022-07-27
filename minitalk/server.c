/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:05:39 by hbostan           #+#    #+#             */
/*   Updated: 2022/07/25 15:31:47 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_catcher(int sig)
{
	static int	i = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c |= 1;
	else
		c |= 0;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, ft_signal_catcher);
	signal(SIGUSR2, ft_signal_catcher);
	while (1)
	{
		pause();
	}
	return (0);
}
