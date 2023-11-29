/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:41:32 by eakman            #+#    #+#             */
/*   Updated: 2023/07/31 13:42:09 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char x);
int		ft_format(va_list *args, char w);
int		ft_int(int w);
int		ft_unsigned(unsigned int w);
int		ft_string(char *str);
int		ft_hex(unsigned int d, char w);
int		ft_point(unsigned long w, int i);
int		ft_check(char str);

#endif
