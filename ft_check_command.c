/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:05:13 by riael             #+#    #+#             */
/*   Updated: 2023/09/16 23:16:55 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_check_command(char *cmd)
{
	char	**args;
	char	*cmd_path;

	args = ft_fill_args(cmd);
	if (args == (void *)0)
		return ((void *)0);
	cmd_path = ft_get_path(args, 0, 0);
	if (args)
		ft_empty_mat(args);
	return (cmd_path);
}
