/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:18:44 by riael             #+#    #+#             */
/*   Updated: 2023/09/16 23:56:14 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_putstr(char *str)
{
	int	i;

	if (str == (void *)0)
		return ;
	i = 0;
	while (str[i] != '\0')
		i += 1;
	write(1, str, i);
}