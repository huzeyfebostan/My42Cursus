/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <huzeyfebostan99@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:59:20 by hbostan           #+#    #+#             */
/*   Updated: 2022/03/24 16:53:02 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_control(char kind, va_list list)
{
	if (kind == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (kind == 's')
		return (ft_putstring(va_arg(list, char *)));
	if (kind == 'p')
		return (ft_putpoint(va_arg(list, unsigned long int)));
	if (kind == 'd' || kind == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (kind == 'u')
		return (ft_putunbr(va_arg(list, unsigned int)));
	if (kind == 'x')
		return (ft_puthex(va_arg(list, unsigned int), LHEXA));
	if (kind == 'X')
		return (ft_puthex(va_arg(list, unsigned int), UHEXA));
	if (kind == '%')
		return (ft_putstring("%"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	va_start (list, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_control(str[i + 1], list);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (len);
}
