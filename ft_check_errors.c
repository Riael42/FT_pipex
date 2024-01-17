/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:14:22 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 16:31:41 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_check_whereis(void);
int		*ft_check_files(char **argv);

int	*ft_check_errors(int argc, char **argv)
{
	int	*files;

	if (argc != 5)
	{
		ft_putstr("Error: Proper usage: ./pipex file1 cmd1 cmd2 file2\n");
		return ((void *)0);
	}
	ft_check_whereis();
	files = ft_check_files(argv);
	return (files);
}

int	*ft_check_files(char **argv)
{
	int	*files;

	files = (int *)malloc(sizeof(int) * 2);
	files[0] = open(argv[1], O_RDONLY);
	files[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (files[0] == -1)
	{
		ft_putstr("|File: ");
		ft_putstr(argv[1]);
		ft_putstr(" does not exist or lacks permissions|\n");
	}
	if (files[1] == -1)
	{
		ft_putstr("|File: ");
		ft_putstr(argv[4]);
		ft_putstr(" does not exist or lacks permissions|\n");
	}
	return (files);
}

void	ft_check_whereis(void)
{
	int	error;

	error = 0;
	error += access("/usr/bin/whereis", F_OK);
	error += access("/usr/bin/whereis", X_OK);
	if (error != 0)
	{
		ft_putstr("|Whereis is a requirement to run this|\n");
		ft_putstr("|program. Please make sure it exists,|\n");
		ft_putstr("|or that you have proper permissions.|\n");
	}
}
