/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:44:03 by syanak            #+#    #+#             */
/*   Updated: 2024/11/30 12:55:48 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_format(va_list va, const char *ptr)
{
	if (*ptr == 'c')
		return (ft_putchar(va_arg(va, int)));
	else if (*ptr == 's')
		return (ft_putstr(va_arg(va, char *)));
	else if (*ptr == 'p')
		return ((ft_put_address(va_arg(va, void *))));
	else if (*ptr == 'd' || *ptr == 'i')
		return (ft_put_number(va_arg(va, int)));
	else if (*ptr == 'u')
		return (ft_put_unumber(va_arg(va, unsigned int)));
	else if (*ptr == 'x')
		return (ft_hex(va_arg(va, unsigned int), 1));
	else if (*ptr == 'X')
		return (ft_hex(va_arg(va, unsigned int), 0));
	else if (*ptr == '%')
		return (ft_putchar(*ptr));
	else
		return (0);
}

int	ft_chech(const char *ptr)
{
	return (*ptr == 'c' || *ptr == 's' || *ptr == 'p'
		|| *ptr == 'd' || *ptr == 'i' || *ptr == 'u'
		|| *ptr == 'x' || *ptr == 'X' || *ptr == '%');
}

int	ft_printf(const char *ptr, ...)
{
	va_list	va;
	int		ret;
	int		print;

	va_start(va, ptr);
	ret = 0;
	if (!ptr || (*ptr == '%' && *(ptr + 1) == '\0'))
		return (va_end(va), -1);
	while (*ptr)
	{
		if (*ptr == '%' && ft_chech(ptr + 1))
		{
			print = ft_format(va, ptr + 1);
			if (print == -1)
				return (va_end(va), -1);
			ret += print;
			ptr++;
		}
		else if (++ret && ft_putchar(*ptr) == -1)
			return (va_end(va), -1);
		ptr++;
	}
	return (va_end(va), ret);
}
