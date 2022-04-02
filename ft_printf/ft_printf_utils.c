/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <huzeyfebostan99@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:35:58 by hbostan           #+#    #+#             */
/*   Updated: 2022/03/22 13:32:56 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint(size_t n)
{
	char	s[16];
	int		i;

	if (n == 0)
		return (ft_putstring("0x0"));
	i = 15;
	while (n)
	{
		s[i--] = LHEXA[n % 16];
		n /= 16;
	}
	i++;
	return (ft_putstring("0x") + write(1, s + i, 16 - i));
}

int	ft_putstring(char *s)
{
	const char	*p;

	if (s == NULL)
		return (write(1, "(null)", 6));
	p = s;
	while (*p)
		p++;
	return (write(1, s, p - s));
}

int	ft_putnbr(long long nbr)
{
	char	s[10];
	int		i;
	int		len;

	i = 9;
	len = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr < 0)
	{
		nbr *= -1;
		len += ft_putchar('-');
	}
	while (nbr)
	{
		*(s + i--) = nbr % 10 + 48;
		nbr /= 10;
	}
	i++;
	return (len + write(1, s + i, 10 - i));
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putnbr(n / 10);
	i += ft_putnbr(n % 10);
	return (i);
}

int	ft_puthex(unsigned int n, char *hex)
{
	char	str[16];
	int		i;
	int		len;

	if (n == 0)
		return (ft_putchar('0'));
	ft_bzero (str, 16);
	i = 0;
	len = 0;
	while (n)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	while (i--)
		len += write(1, &str[i], 1);
	return (len);
}

int main()
{
	ft_printf("%asdbd",12);
	printf("%dsdbd",12);
}