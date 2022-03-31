/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:28:04 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/28 11:28:21 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_elements(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
		free(elements[i++]);
	free(elements);
}

int	pipe_test(t_pipex *data)
{
	if (pipe(data->outputs) < 0)
	{
		perror("Pipe error");
		return (0);
	}
	return (1);
}

int	close_wait(t_pipex *data)
{
	close(data->outputs[0]);
	close(data->outputs[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	return (1);
}
