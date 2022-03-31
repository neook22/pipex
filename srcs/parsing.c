/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:30:48 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/28 10:41:35 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_commands(t_pipex *data, char **argv)
{
	data->command1 = ft_split(argv[1], ' ');
	if (!data->command1)
		return (0);
	data->command2 = ft_split(argv[2], ' ');
	if (!data->command2)
		return (0);
	return (1);
}

int	clear_env(char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[0][i] != '=')
		i++;
	i++;
	tmp = ft_substr(env[0], i, ft_strlen(env[0]) - i);
	if (!tmp)
		return (0);
	free(env[0]);
	env[0] = tmp;
	return (1);
}

char	**get_env_files(char **envp)
{
	int		i;
	char	*env_line;
	char	**env_paths;

	i = 0;
	while (!ft_strcmp(envp[i], "PATH"))
		i++;
	env_line = ft_strdup(envp[i]);
	if (!env_line)
		return (NULL);
	env_paths = ft_split(env_line, ':');
	if (!env_paths)
		return (NULL);
	if (!clear_env(env_paths))
		return (NULL);
	free(env_line);
	return (env_paths);
}

char	*check_commands(char **env, char **command)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (env[i])
	{
		tmp = ft_strjoin("/", command[0]);
		tmp2 = ft_strjoin(env[i], tmp);
		free(tmp);
		if (access(tmp2, F_OK) != -1)
			return (tmp2);
		free(tmp2);
		i++;
	}
	perror("Access error");
	return (NULL);
}

int	commands_handler(char **argv, char **envp, t_pipex *data)
{
	char	**env;

	if (!init_commands(data, argv))
		return (0);
	env = get_env_files(envp);
	if (!env)
		return (0);
	data->path_command1 = check_commands(env, data->command1);
	data->path_command2 = check_commands(env, data->command2);
	free_elements(env);
	if (!data->path_command1 || !data->path_command2)
		return (0);
	return (1);
}
