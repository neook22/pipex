/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:43:15 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/28 11:30:20 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_pipex
{
	char	**command1;
	char	**command2;
	char	*path_command1;
	char	*path_command2;
	int		outputs[2];
	int		fd;
	int		pid1;
	int		pid2;
}				t_pipex;

/* parsing */
int		commands_handler(char **argv, char **envp, t_pipex *data);

/* pipex */
int		pipex(t_pipex *data, char **argv);
int		pipe_test(t_pipex *data);
int		close_wait(t_pipex *data);
void	free_elements(char **elements);

#endif