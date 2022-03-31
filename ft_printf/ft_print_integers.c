/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:17:41 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 10:59:52 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integers(int nb)
{
	unsigned int	n;
	int				ret;

	ret = 0;
	if (nb < 0)
	{
		n = (unsigned int)-nb;
		ft_putchar('-');
		ret++;
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
	{
		ret += ft_print_integers(n / 10);
		ret += ft_print_integers(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		ret++;
	}
	return (ret);
}
