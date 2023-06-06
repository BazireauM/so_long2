/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:09:03 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/06 14:23:42 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	test_way(struct s_map *map)
{
	char	**map_cp;
	int		i;

	i = 1;
	map_cp = cpy_map(map);
	map_cp = init_shearch_way(map_cp);
	while (i == 1)
	{
		i = search_way(map_cp);
	}
	if (count_e_and_c(map_cp) != 0)
	{
		free_all_final(map_cp);
		return (1);
	}
	free_all_final(map_cp);
	return (0);
}

int	search_way(char **map_cp)
{
	int	i;
	int	b;

	i = 0;
	while (map_cp[i])
	{
		b = 0;
		while (map_cp[i][b])
		{
			if (test_new_case(map_cp, i, b) == 1)
			{
				return (1);
			}
			b++;
		}
		i++;
	}
	return (0);
}

int	test_new_case(char **map_cp, int i, int b)
{
	int	a;

	a = 0;
	if (map_cp[i][b] == '3')
	{
		if ((map_cp[i + 1][b] != '1' && map_cp[i + 1][b] != '3') ||
			(map_cp[i - 1][b] != '1' && map_cp[i - 1][b] != '3') ||
			(map_cp[i][b + 1] != '1' && map_cp[i][b + 1] != '3') ||
			(map_cp[i][b - 1] != '1' && map_cp[i][b - 1] != '3'))
			a = 1;
		if (map_cp[i + 1][b] != '1')
			map_cp[i + 1][b] = '3';
		if (map_cp[i - 1][b] != '1')
			map_cp[i - 1][b] = '3';
		if (map_cp[i][b + 1] != '1')
			map_cp[i][b + 1] = '3';
		if (map_cp[i][b - 1] != '1')
			map_cp[i][b - 1] = '3';
		return (a);
	}
	return (0);
}

char	**cpy_map(struct s_map *map)
{
	char	**map_cp;
	int		i;
	int		b;

	map_cp = malloc(sizeof(char *) * (map->leny + 1));
	if (!map_cp)
		return (NULL);
	i = 0;
	while (map->map[i])
	{
		map_cp[i] = malloc(sizeof(char *) * (ft_strlen(map->map[i]) + 1));
		b = 0;
		while (map->map[i][b])
		{
			map_cp[i][b] = map->map[i][b];
			b++;
		}
		map_cp[i][b] = '\0';
		i++;
	}
	map_cp[i] = NULL;
	return (map_cp);
}

char	**init_shearch_way(char **map_cp)
{
	int	i;
	int	b;

	i = 0;
	while (map_cp[i])
	{
		b = 0;
		while (map_cp[i][b])
		{
			if (map_cp[i][b] == 'P')
				map_cp[i][b] = '3';
			b++;
		}
		i++;
	}
	return (map_cp);
}
