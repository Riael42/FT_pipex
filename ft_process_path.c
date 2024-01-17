/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:20:10 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 14:16:12 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_process_path(char **args, int size, char *path)
{
	char	*ret;

	if (size == ft_strlen(args[1]) + 2)
	{
		ft_putstr("Command: ");
		ft_putstr(args[1]);
		ft_putstr(" not found!\n");
		return ((void *)0);
	}
	path[size] = '\0';
	ret = ft_cook_path(path, 0, 0);
	return (ret);
}
