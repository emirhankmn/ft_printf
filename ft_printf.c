/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:40:50 by eakman            #+#    #+#             */
/*   Updated: 2023/07/31 20:57:25 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_format(va_list *args, char a)
{
	if (a == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (a == 'd' || a == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (a == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (a == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (a == 'X' || a == 'x')
		return (ft_hex(va_arg((*args), unsigned int), a));
	else if (a == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else
		return (ft_putchar('%'));
}

int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		tmp;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]))
		{
			tmp = ft_format(&args, str[++i]);
			if (tmp == -1)
				return (-1);
			len += tmp - 1;
		}
		else if (ft_putchar(str[i]) == -1)
			return (-1);
		len++;
	}
	va_end(args);
	return (len);
}
