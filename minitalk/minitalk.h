/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:05:35 by hbostan           #+#    #+#             */
/*   Updated: 2022/07/25 13:31:26 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/***** HEADERS ***/
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

/***** client.c *****/
static int	control(char c);
static int	ft_atoi(const char *nptr);
static void	ft_send_message(pid_t pid, char *str);

/***** server.c *****/
void		ft_signal_catcher(int sig);

#endif
