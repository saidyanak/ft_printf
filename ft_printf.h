/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:04:36 by syanak            #+#    #+#             */
/*   Updated: 2024/11/27 13:31:29 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *ptr, ...);
int	ft_putchar(int c);
int	ft_put_address(void *adrs);
int	ft_putstr(char *s);
int	ft_hex(unsigned int address, int type);
int	ft_put_number(int number);
int	ft_put_unumber(unsigned int number);
int	ft_chech(const char *ptr);
int	ft_address(unsigned long address);

#endif
