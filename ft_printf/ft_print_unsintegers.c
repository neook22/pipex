/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsintegers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:04:03 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 11:00:08 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsintegers(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb >= 10)
	{
		ret += ft_print_unsintegers(nb / 10);
		ret += ft_print_unsintegers(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		ret++;
	}
	return (ret);
}
