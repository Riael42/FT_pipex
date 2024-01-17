/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:54:36 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 00:00:19 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int		ft_cutend(char *str, char c);
int		ft_skipstart(char *str, char c);
char	**ft_zerowords(void);

int	ft_countwords(char *str, char c)
{
	size_t	i;
	size_t	l;
	int		wc;

	if (!str || str[0] == '\0')
		return (0);
	i = ft_skipstart(str, c);
	if (str[i] == '\0')
		return (0);
	l = ft_cutend(str, c);
	wc = 1;
	while (i < l)
	{
		while (str[i] != c && i < l && str[i] != '\0')
			i += 1;
		if (str[i] != '\0' && i < l)
			wc += 1;
		while (str[i] == c && i < l && str[i] != '\0')
			i += 1;
	}
	return (wc);
}

int	ft_cutend(char *str, char c)
{
	int	l;

	l = ft_strlen(str);
	while (str[l] == c || str[l] == '\0')
		l -= 1;
	return (l);
}

int	ft_skipstart(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] != '\0' && str[i] == c)
		i += 1;
	return (i);
}

char	**ft_zerowords(void)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * 1);
	s[0] = ((void *)0);
	return (s);
}
