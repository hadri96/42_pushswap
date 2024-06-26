/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:51:45 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/26 10:52:14 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_strcmp(char *s1, char *s2)
{
	if (!*s1 || !*s2)
		return (false);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	return (true);
}

bool	ft_is_valid_digit(char *str)
{
	if (ft_strlen(str) == 10 && ft_strncmp(str, "2147483647", 10) > 0)
		return (false);
	if (*str == '-')
		str++;
	if ((ft_strlen(str) == 0) || \
		(ft_strlen(str) == 10 && ft_strncmp(str, "2147483648", 10) > 0) || \
		(ft_strlen(str) > 10))
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

bool	contains_doubles(char **numbers)
{
	int	i;

	while (numbers[1])
	{
		i = 1;
		while (numbers[i])
		{
			if (ft_strcmp(*numbers, numbers[i++]))
				return (true);
		}
		numbers++;
	}
	return (false);
}

char	*join_strarr(char **argv, int argc)
{
	int		i;
	int		j;
	int		k;
	char	*result;
	int		length;

	if (argc == 2)
		return (argv[1]);
	i = 1;
	while (i < argc)
		length = length + ft_strlen(argv[i++]) + 1;
	i = 0;
	k = 0;
	result = galloc(sizeof(char) * (length));
	if (!result)
		return (NULL);
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
			result[k++] = argv[i][j++];
		result[k++] = ' ';
	}
	result[k - 1] = '\0';
	return (result);
}
