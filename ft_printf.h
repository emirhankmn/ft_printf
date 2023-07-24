/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:42:16 by eakman            #+#    #+#             */
/*   Updated: 2023/07/25 01:31:02 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_string(char *str);
int		ft_unsigned(unsigned int a);
int		ft_unsigned(unsigned int a);
int		ft_format(va_list arg, char c);
int		ft_hex(unsigned int a, char b);
int		ft_printf(const char *str, ...);
int		ft_point(unsigned long ptr, int nbr);
char	*ft_itoa(int n);
int	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_int(int src);
int		ft_putchar(char a);

#endif
