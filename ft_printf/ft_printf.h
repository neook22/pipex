/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:58:47 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 11:20:09 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);

int		ft_printf(const char *s, ...);
int		ft_print_str(char	*str);
int		ft_print_char(int c);
int		ft_print_integers(int nb);
int		ft_print_unsintegers(unsigned int nb);
int		ft_print_hexa(unsigned int nb);
int		ft_print_upper_hexa(unsigned int nb);
int		ft_print_pointer(size_t p);

#endif