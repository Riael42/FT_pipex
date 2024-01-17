/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:26:46 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 14:07:00 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_stop_pipe(char **cmd1_args, char **cmd2_args, \
					char **cmd_path, int *files);

void	ft_start_pipe(char **argv, int *files)
{
	char	*cmd_path[2];
	char	**cmd1_args;
	char	**cmd2_args;

	cmd1_args = ft_split(argv[2], ' ');
	cmd2_args = ft_split(argv[3], ' ');
	cmd_path[0] = ft_check_command(argv[2]);
	cmd_path[1] = ft_check_command(argv[3]);
	if (cmd_path[1] != ((void *)0))
		ft_pipex(cmd_path, files, cmd1_args, cmd2_args);
	ft_stop_pipe(cmd1_args, cmd2_args, cmd_path, files);
}

void	ft_stop_pipe(char **cmd1_args, char **cmd2_args, \
					char **cmd_path, int *files)
{
	if (cmd1_args != (void *)0)
		ft_empty_mat(cmd1_args);
	if (cmd2_args != (void *)0)
		ft_empty_mat(cmd2_args);
	if (cmd_path[0] != (void *)0)
		free(cmd_path[0]);
	if (cmd_path[1] != (void *)0)
		free(cmd_path[1]);
	if (files[0] != -1)
		close(files[0]);
	if (files[1] != -1)
		close(files[1]);
}
