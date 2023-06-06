/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:05:54 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/06 14:19:08 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	test_char(struct s_map *map)
{
	if (test_char_p(map) == 1 || test_char_e(map) == 1 || test_char_c(map) == 1)
		return (1);
	return (0);
}

int	test_char_p(struct s_map *map)
{
	int	i;
	int	b;
	int	test;

	i = 0;
	test = 0;
	while (map->map[i])
	{
		b = 0;
		while (map->map[i][b])
		{
			if (map->map[i][b] == 'P')
				test++;
			b++;
		}
		i++;
	}
	if (test != 1)
		return (1);
	return (0);
}

int	test_char_e(struct s_map *map)
{
	int	i;
	int	b;
	int	test;

	i = 0;
	test = 0;
	while (map->map[i])
	{
		b = 0;
		while (map->map[i][b])
		{
			if (map->map[i][b] == 'E')
				test++;
			b++;
		}
		i++;
	}
	if (test != 1)
		return (1);
	return (0);
}

int	test_char_c(struct s_map *map)
{
	int	i;
	int	b;
	int	test;

	i = 0;
	test = 0;
	while (map->map[i])
	{
		b = 0;
		while (map->map[i][b])
		{
			if (map->map[i][b] == 'C')
				test++;
			b++;
		}
		i++;
	}
	if (test < 1)
		return (1);
	return (0);
}

int	count_e_and_c(char **map_cp)
{
	int	i;
	int	b;

	i = 0;
	while (map_cp[i])
	{
		b = 0;
		while (map_cp[i][b])
		{
			if (map_cp[i][b] == 'E' || map_cp[i][b] == 'C')
				return (1);
			b++;
		}
		i++;
	}
	return (0);
}
