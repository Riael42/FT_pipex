/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:17:19 by riael             #+#    #+#             */
/*   Updated: 2023/09/16 23:18:40 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == ((void *)0))
		return (0);
	i = 0;
	while (s[i] != '\0')
		i += 1;
	return (i);
}