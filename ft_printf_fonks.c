/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fonks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:37:08 by syanak            #+#    #+#             */
/*   Updated: 2024/11/30 13:33:03 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;
	int	tp;

	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (*s)
	{
		tp = ft_putchar(*s);
		if (tp == -1)
			return (-1);
		len += tp;
		s++;
	}
	return (len);
}

int	ft_put_address(void *adrs)
{
	unsigned long	address;
	int				count;
	int				tmp;

	if (!adrs)
		return (write(1, "(nil)", 5));
	count = 0;
	address = (unsigned long)adrs;
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	tmp = ft_address(address);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}

int	ft_address(unsigned long address)
{
	int	count;
	int	tmp;

	count = 0;
	if (address >= 16)
	{
		tmp = ft_address(address / 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar("0123456789abcdef"[address % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_hex(unsigned int address, int type)
{
	int	count;
	int	tmp;

	count = 0;
	if (address >= 16)
	{
		tmp = ft_hex(address / 16, type);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (type == 0)
	{
		if (ft_putchar("0123456789ABCDEF"[address % 16]) == -1)
			return (-1);
	}
	else if (type == 1)
	{
		if (ft_putchar("0123456789abcdef"[address % 16]) == -1)
			return (-1);
	}
	return (count + 1);
}
