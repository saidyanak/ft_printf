/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:04:36 by syanak            #+#    #+#             */
/*   Updated: 2024/11/12 02:05:55 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int	ft_printf(const char *ptr, ...);
int	ft_putchar(int c);
int	ft_put_address(void *adrs);
int	ft_putstr(char *s);
int	ft_hex(size_t address, int type);
int	ft_put_number(int number);
int	ft_put_unumber(unsigned int number);
int	ft_chech(const char *ptr);

#endif
