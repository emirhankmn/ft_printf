/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:59:51 by eakman            #+#    #+#             */
/*   Updated: 2023/07/25 01:22:35 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return(write(1, "(null)", 6));
	}
	while (str[i])
	{
		if(write(1, &str[i], 1) == -1)
			return(-1);
		i++;
	}
	return (i);
}

int	ft_point(unsigned long ptr, int nbr)
{
	int	len;

	len = 0;
	if (nbr == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		len += 2;
		nbr = 0;
	}
	if (ptr >= 16)
		len += ft_point(ptr / 16, 0);
	if (write(1, &"0123456789abcdef"[ptr % 16], 1) == -1)
		return(-1);
	return (len + 1);
}

int	ft_int(int src)
{
	int		len;
	char	*tmp;
	len = 1;
	if(src == 0)
	{
		return(ft_putchar('0'));
	}
	tmp = ft_itoa(src);
	if (tmp == NULL)
		return (-1);
	len = ft_strlen(tmp);
	ft_putstr(tmp);
	free(tmp);
	return (len);
}

int	ft_unsigned(unsigned int a)
{
	int	len;

	len = 0;
	if (a >= 10)
		len += ft_unsigned(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (len + 1);
}

int	ft_hex(unsigned int a, char b)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_hex(a / 16, b);
	if (b == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	if (b == 'X')
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (len + 1);
}
