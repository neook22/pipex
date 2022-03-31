/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:52:10 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 11:21:12 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(size_t p)
{
	int	ret;

	ret = 0;
	if (p >= 16)
	{
		ret += ft_print_pointer(p / 16);
		ret += ft_print_pointer(p % 16);
	}
	else if (p >= 10 && p <= 15)
	{
		ft_putchar((p + 39) + '0');
		ret++;
	}
	else
	{
		ft_putchar(p + '0');
		ret++;
	}
	return (ret);
}
