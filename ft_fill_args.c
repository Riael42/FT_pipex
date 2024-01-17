/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:24:50 by riael             #+#    #+#             */
/*   Updated: 2023/09/16 23:33:20 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**ft_fill_args(char *cmd)
{
	char	**args;
	int		i;

	i = 0;
	if (cmd == (void *)0)
		return ((void *)0);
	args = (char **)malloc(sizeof(char *) * 3);
	if (args == (void *)0)
		return ((void *)0);
	args[0] = ft_strdup("whereis");
	while (cmd[i] != ' ' && cmd[i] != '\0')
		i += 1;
	args[1] = ft_strdupi(cmd, i);
	args[2] = ((void *)0);
	if (args[0] == ((void *)0) || args[1] == ((void *)0))
		ft_empty_mat(args);
	return (args);
}
