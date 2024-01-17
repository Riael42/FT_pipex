/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:51:16 by riael             #+#    #+#             */
/*   Updated: 2023/09/16 22:56:33 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_createword(char *str, char c, int curword);
int		ft_skipword(char *str, char c, int i);
int		ft_skipspace(char *str, char c, int i);

char	**ft_split(char *s, char c)
{
	int		wc;
	char	**final;
	int		i;

	wc = ft_countwords(s, c);
	if (wc == 0)
		return (ft_zerowords());
	final = (char **)malloc(sizeof(char *) * (wc + 1));
	if (final == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < wc)
	{
		final[i] = ft_createword(s, c, i);
		i += 1;
	}
	final[wc] = ((void *)0);
	return (final);
}

char	*ft_createword(char *str, char c, int curword)
{
	int		i;
	int		size;
	char	*word;

	i = ft_skipspace(str, c, 0);
	size = 0;
	while (curword > 0)
	{
		i = ft_skipword(str, c, i);
		i = ft_skipspace(str, c, i);
		curword -= 1;
	}
	while (str[i + size] != c && str[i + size] != '\0')
		size += 1;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (word == ((void *)0))
		return ((void *)0);
	word[size] = '\0';
	size -= 1;
	while (size >= 0)
	{
		word[size] = str[i + size];
		size -= 1;
	}
	return (word);
}

int	ft_skipword(char *str, char c, int i)
{
	while (str[i] != c && str[i] != '\0')
		i += 1;
	return (i);
}

int	ft_skipspace(char *str, char c, int i)
{
	while (str[i] == c && str[i] != '\0')
		i += 1;
	return (i);
}
