/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:11:53 by eakman            #+#    #+#             */
/*   Updated: 2023/07/24 23:56:49 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return(write(1, &a, 1));
}

int	ft_format(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg((arg), int)));
	else if (c == 's')
		return (ft_string(va_arg((arg), char *)));
	else if (c == 'p')
		return (ft_point(va_arg((arg), unsigned long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg((arg), int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg((arg), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((arg), unsigned int), c));
	else
		return (ft_putchar('%'));
}

bool	ft_flag_catch(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
			|| str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == '%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;
	int tmp;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (ft_flag_catch(str, i))
		{
			tmp = ft_format(arg, str[++i]);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			if(write(1, &str[i], 1) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
/* #include <stdio.h>

int main()
{
	int tmp = ft_printf("%%c");
	ft_printf("%d",tmp);
	tmp = printf("%%c");
	printf("%d",tmp);
	
} */