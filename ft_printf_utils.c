/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:41:24 by eakman            #+#    #+#             */
/*   Updated: 2023/07/31 21:13:05 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int a)
{
	int	len;
	int	tmp;

	len = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		a *= -1;
	}
	if (a >= 10)
	{
		tmp = ft_int(a / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[a % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int a)
{
	int	len;
	int	tmp;

	len = 0;
	if (a >= 10)
	{
		tmp = ft_unsigned(a / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[a % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[++i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hex(unsigned int d, char a)
{
	int	len;
	int	tmp;

	len = 0;
	if (d >= 16)
	{
		tmp = ft_hex(d / 16, a);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (a == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[d % 16], 1) == -1)
			return (-1);
	}
	if (a == 'x')
	{
		if (write(1, &"0123456789abcdef"[d % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_point(unsigned long a, int i)
{
	int	len;
	int	tmp;

	len = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		len += 2;
	}
	if (a >= 16)
	{
		tmp = ft_point(a / 16, i);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
		return (-1);
	return (len + 1);
}
