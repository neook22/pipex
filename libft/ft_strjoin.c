/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:42:41 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/28 10:42:45 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joiner;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joiner = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	if (joiner == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		joiner[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		joiner[i] = *s2;
		i++;
		s2++;
	}
	joiner[i] = '\0';
	return (joiner);
}
