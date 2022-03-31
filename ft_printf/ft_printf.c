/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:01:20 by sacha             #+#    #+#             */
/*   Updated: 2022/03/07 11:26:48 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_conditions(const char *format, va_list next_arg, int pos)
{
	int	ret;

	ret = 0;
	if (!format[pos])
		return (0);
	if (format[pos] == '%' && format[pos + 1] == 'c')
			ret += ft_print_char(va_arg(next_arg, int));
	else if (format[pos] == '%' && format[pos + 1] == 's')
		ret += ft_print_str(va_arg(next_arg, char *));
	else if (format[pos] == '%' && (format
			[pos + 1] == 'd' || format[pos + 1] == 'i'))
		ret += ft_print_integers(va_arg(next_arg, int));
	else if (format[pos] == '%' && format[pos + 1] == 'u')
		ret += ft_print_unsintegers(va_arg(next_arg, unsigned int));
	else if (format[pos] == '%' && format[pos + 1] == 'x')
		ret += ft_print_hexa(va_arg(next_arg, unsigned int));
	else if (format[pos] == '%' && format[pos + 1] == 'X')
		ret += ft_print_upper_hexa(va_arg(next_arg, unsigned int));
	else if (format[pos] == '%' && format[pos + 1] == 'p')
	{
		ret += ft_print_str("0x");
		ret += ft_print_pointer((size_t)va_arg(next_arg, void *));
	}
	return (ret);
}

void	ft_printf_helper(const char *format, int *ret, int *i, va_list next_arg)
{
	if (format[*i + 1] != '%')
		*ret += ft_printf_conditions(format, next_arg, *i);
	else
	{
		ft_print_char('%');
		*ret += 1;
	}
	*i += 2;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	next_arg;

	i = 0;
	ret = 0;
	va_start(next_arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_print_char(format[i]);
			ret++;
			i++;
		}
		else if (format[i] == '%')
			ft_printf_helper(format, &ret, &i, next_arg);
	}
	va_end(next_arg);
	return (ret);
}
