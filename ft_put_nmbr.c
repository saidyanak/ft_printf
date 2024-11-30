/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nmbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:07:31 by syanak            #+#    #+#             */
/*   Updated: 2024/11/30 13:11:35 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_number(int number)
{
	long	ret;
	int		value;
	int		len;

	value = 0;
	ret = number;
	if (number == 0)
		return (ft_putchar('0'));
	if (number < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		ret = -ret;
		value ++;
	}
	if (ret > 9)
	{
		len = ft_put_number(ret / 10);
		if (len == -1)
			return (-1);
		value += len;
	}
	if (ft_putchar("0123456789"[ret % 10]) == -1)
		return (-1);
	return (value + 1);
}

int	ft_put_unumber(unsigned int number)
{
	int	value;
	int	len;

	len = 0;
	if (number > 9)
	{
		value = ft_put_unumber(number / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789"[number % 10]) == -1)
		return (-1);
	return (len + 1);
}
