/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:57:46 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/09 10:36:01 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	test_name_file(char *s)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] == '.')
			b++;
		i++;
	}
	if (b != 1)
		return (1);
	if (s[i - 1] == 'r' && s[i - 2] == 'e' && s[i - 3] == 'b'
		&& s[i - 4] == '.')
		return (0);
	return (1);
}

int	test_map(struct s_map *map)
{
	if (rectangle(map) == 1)
	{
		ft_printf("error map not rectangle\n");
		return (1);
	}
	if (surrounded(map) == 1)
	{
		ft_printf("error map no surronded by wall\n");
		return (1);
	}
	if (test_char(map) == 1)
	{
		ft_printf("error item\n");
		return (1);
	}
	if (test_way(map) == 1)
	{
		ft_printf("error no way possible\n");
		return (1);
	}
	return (0);
}

int	rectangle(struct s_map *map)
{
	int	i;
	int	len;

	len = ft_strlen(map->map[0]);
	i = 1;
	while (map->map[i + 1])
	{
		if ((int)ft_strlen(map->map[i]) != len)
			return (1);
		i++;
	}
	if ((int)ft_strlen(map->map[i]) != len - 1)
		return (1);
	i++;
	map->lenx = len - 1;
	map->leny = i;
	return (0);
}

int	surrounded(struct s_map *map)
{
	int	i;

	i = 0;
	while (i < map->lenx - 1)
	{
		if (map->map[0][i] != '1')
			return (1);
		if (map->map[map->leny - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < map->leny - 1)
	{
		if (map->map[i][0] != '1')
			return (1);
		if (map->map[i][map->lenx - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
