/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:12:02 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 16:32:20 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv)
{
	int	*files;

	files = ft_check_errors(argc, argv);
	if (files == (void *)0)
		return (0);
	if (files[1] == -1)
	{
		if (files)
			free(files);
		return (-1);
	}
	ft_start_pipe(argv, files);
	if (files)
		free(files);
	return (0);
}
