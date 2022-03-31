/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:35:20 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 10:59:39 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb >= 16)
	{
		ret += ft_print_hexa(nb / 16);
		ret += ft_print_hexa(nb % 16);
	}
	else if (nb >= 10 && nb <= 15)
	{
		ft_putchar((nb - 10) + 'a');
		ret++;
	}
	else
	{
		ft_putchar(nb + '0');
		ret++;
	}
	return (ret);
}
