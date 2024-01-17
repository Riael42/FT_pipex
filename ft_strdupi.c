/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:34:28 by riael             #+#    #+#             */
/*   Updated: 2023/09/16 23:47:41 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_strdupi(char *cmd, int i)
{
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == ((void *)0))
		return ((void *)0);
	str[i] = '\0';
	j = 0;
	while (j < i)
	{
		str[j] = cmd[j];
		j += 1;
	}
	return (str);
}
