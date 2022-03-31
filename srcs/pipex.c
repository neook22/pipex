/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:43:46 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/28 11:28:08 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_close(t_pipex *data)
{
	close(data->outputs[0]);
	close(data->outputs[1]);
	close(data->fd);
	if (execve(data->path_command1, data->command1, NULL) == -1)
		return (0);
	return (1);
}

int	exec_close2(t_pipex *data)
{
	close(data->outputs[0]);
	close(data->outputs[1]);
	close(data->fd);
	if (execve(data->path_command2, data->command2, NULL) == -1)
		return (0);
	return (1);
}

int	child_process(t_pipex *data, char **argv)
{
	data->fd = open(argv[0], O_RDONLY);
	if (data->fd < 0)
	{
		close(data->outputs[0]);
		close(data->outputs[1]);
		return (0);
	}
	if (dup2(data->fd, STDIN_FILENO) < 0)
	{
		close(data->fd);
		close(data->outputs[0]);
		close(data->outputs[1]);
		perror("dup2() error\n");
		return (0);
	}
	if (dup2(data->outputs[1], STDOUT_FILENO) < 0)
	{
		close(data->outputs[0]);
		close(data->outputs[1]);
		close(data->fd);
		perror("dup2() error\n");
		return (0);
	}
	return (exec_close(data));
}

int	parent_process(t_pipex *data, char **argv)
{
	data->fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC);
	if (data->fd < 0)
	{
		close(data->outputs[0]);
		close(data->outputs[1]);
		return (0);
	}
	if (dup2(data->fd, STDOUT_FILENO) < 0)
	{
		close(data->fd);
		close(data->outputs[0]);
		close(data->outputs[1]);
		perror("dup2() error\n");
		return (0);
	}
	if (dup2(data->outputs[0], STDIN_FILENO) < 0)
	{
		close(data->fd);
		close(data->outputs[0]);
		close(data->outputs[1]);
		perror("dup2() error\n");
		return (0);
	}
	return (exec_close2(data));
}

int	pipex(t_pipex *data, char **argv)
{
	if (!pipe_test(data))
		return (0);
	data->pid1 = fork();
	if (data->pid1 < 0)
	{
		perror("Fork error");
		return (0);
	}
	if (!data->pid1)
	{
		if (!child_process(data, argv))
			return (0);
	}
	data->pid2 = fork();
	if (data->pid2 < 0)
	{
		perror("Fork error");
		return (0);
	}
	if (data->pid2 == 0)
	{
		if (!parent_process(data, argv))
			return (0);
	}
	return (close_wait(data));
}
