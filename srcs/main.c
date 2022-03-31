/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:05:45 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/28 10:51:29 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc, char **argv, char **envp, t_pipex *data)
{
	argv++;
	if (argc != 5)
	{
		ft_printf("Wrong arguments number\n");
		return (0);
	}
	if (access(argv[0], F_OK) < 0)
	{
		perror("Access error");
		return (0);
	}
	if (!commands_handler(argv, envp, data))
	{
		ft_printf("Command 1 or command 2 not found.\n");
		return (0);
	}
	if (!pipex(data, argv))
	{
		free_elements(data->command1);
		free_elements(data->command2);
		free(data->path_command1);
		free(data->path_command2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (!check_args(argc, argv, envp, &data))
		return (EXIT_FAILURE);
	free_elements(data.command1);
	free_elements(data.command2);
	free(data.path_command1);
	free(data.path_command2);
	return (EXIT_SUCCESS);
}
