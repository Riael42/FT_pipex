/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:47:46 by riael             #+#    #+#             */
/*   Updated: 2023/09/16 23:50:54 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	if (s == (void *)0)
		return ((void *)0);
	i = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == (void *)0)
		return ((void *)0);
	dest[i] = '\0';
	while (i > 0)
	{
		dest[i] = s[i];
		i -= 1;
	}
	dest[0] = s[0];
	return (dest);
}
