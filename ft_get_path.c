/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:03:58 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 16:15:43 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_get_path0(int *pipes, char *path, int size, char **args);
void	ft_get_path1(int *pipes, char **args);

char	*ft_get_path(char **args, int piper, int size)
{
	pid_t	pid;
	char	*path;
	int		pipes[2];

	path = (char *)malloc(sizeof(char) * 101);
	piper = pipe(pipes);
	pid = fork();
	if (path == (void *)0 || pid == -1 || piper == -1)
		return ((void *)0);
	if (pid == 0)
	{
		return (ft_get_path0(pipes, path, size, args));
	}
	else
		ft_get_path1(pipes, args);
	ft_putstr("If you read this you've been alpha particle'd\n");
	return ((void *)0);
}

char	*ft_get_path0(int *pipes, char *path, int size, char **args)
{
	char	*ret;

	close(pipes[1]);
	dup2(pipes[0], STDIN_FILENO);
	size = read(pipes[0], path, 100);
	if (size == -1)
	{
		ft_putstr("Error reading from pipe\n");
		return ((void *)0);
	}
	path[size] = '\0';
	close(pipes[0]);
	ret = ft_process_path(args, size, path);
	if (path != (void *)0)
		free(path);
	return (ret);
}

void	ft_get_path1(int *pipes, char **args)
{
	close(pipes[0]);
	dup2(pipes[1], STDOUT_FILENO);
	execve("/usr/bin/whereis", args, (void *)0);
	close(pipes[1]);
}
