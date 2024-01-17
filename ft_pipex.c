/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:19 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 14:28:09 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_pipex_parent(int *end, int file, char **cmd2args, char *cmd_path);
void	ft_pipex_child(int	*end, int file, char **cmd1args, char *cmd_path);

void	ft_pipex(char **cmd_path, int *files, char **cmd1args, char **cmd2args)
{
	int		end[2];
	int		status;
	int		piper;
	pid_t	pid[2];

	piper = pipe(end);
	if (piper == -1)
		return (ft_putstr("Call a plumber your pipes whack\n"));
	pid[0] = fork();
	if (pid[0] < 0)
		return (ft_putstr("Your philosophers have no forks\n"));
	if (pid[0] == 0 && files[0] != -1 && cmd_path[0] != (void *)0)
		ft_pipex_child(end, files[0], cmd1args, cmd_path[0]);
	else
	{
		pid[1] = fork();
		if (pid[1] < 0)
			return (ft_putstr("Your philosophers have no forks\n"));
		if (pid[1] == 0 && pid[0] > 0)
			ft_pipex_parent(end, files[1], cmd2args, cmd_path[1]);
	}
	close(end[0]);
	close(end[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
}

void	ft_pipex_parent(int *end, int file, char **cmd2args, char *cmd_path)
{
	close(end[1]);
	dup2(file, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	execve((const char *)cmd_path, cmd2args, (void *)0);
	close(end[0]);
}

void	ft_pipex_child(int *end, int file, char **cmd1args, char *cmd_path)
{
	close(end[0]);
	dup2(file, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	execve((const char *)cmd_path, cmd1args, (void *)0);
	close(end[1]);
}
