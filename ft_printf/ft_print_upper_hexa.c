/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:56:51 by sacha             #+#    #+#             */
/*   Updated: 2022/03/07 11:00:10 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_hexa(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb >= 16)
	{
		ret += ft_print_upper_hexa(nb / 16);
		ret += ft_print_upper_hexa(nb % 16);
	}
	else if (nb >= 10 && nb <= 15)
	{
		ft_putchar((nb - 10) + 'A');
		ret++;
	}
	else
	{
		ft_putchar(nb + '0');
		ret++;
	}
	return (ret);
}
