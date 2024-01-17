/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cook_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:21:49 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 14:22:23 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_cook_path(char *path, int i, int j)
{
	char	*ret;

	while (path[i] != ' ')
		i += 1;
	i += 1;
	while (path[i] != ' ' && path[i] != '\n' && path[i] != '\0')
	{
		i += 1;
		j += 1;
	}
	ret = (char *)malloc(sizeof(char) * (j + 1));
	if (ret == ((void *)0))
	{
		if (path)
			free(path);
		return ((void *)0);
	}
	ret[j] = '\0';
	while (j > 0)
	{
		j -= 1;
		i -= 1;
		ret[j] = path[i];
	}
	return (ret);
}
