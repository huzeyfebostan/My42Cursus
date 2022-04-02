/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <huzeyfebostan99@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 08:54:29 by hbostan           #+#    #+#             */
/*   Updated: 2022/03/21 16:54:49 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/***** HEADERS ***/
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

/***** MACRO *****/
# define LHEXA "0123456789abcdef"
# define UHEXA "0123456789ABCDEF"

/***** MAİN FİLE ft_printf.c *****/
int	ft_printf(const char *str, ...);
int	ft_control(char kind, va_list list);
int	ft_putchar(char c);

/***** FİLE ft_printf_utils.c *****/
int	ft_putpoint(size_t n);
int	ft_putstring(char *s);
int	ft_putnbr(long long nbr);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, char *hex);

#endif
