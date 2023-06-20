/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:48:28 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/20 16:56:51 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	display_map(t_map *map);

int	main(int argc, char *argv[])
{
	mlx_t	*win;
	t_map	*map;
	t_img	*img;
	t_all	*all;

	if (argc != 2)
		return (0);
	if (test_name_file(argv[1]) == 1)
	{
		ft_printf("error files\n");
		return (0);
	}
	all = malloc(sizeof(t_all) * 1);
	map = malloc(sizeof(t_map) * 1);
	map->map = parssing(argv[1]);
	printf("%d\n", test_map(map));
	display_map(map);
	printf("test : %d\n", map->lenx);
	printf("test : %d\n", map->leny);
	win = mlx_init(20 * map->lenx, 20 * map->leny, "so_long", 0);
	img = init_img(win);
	first_print(win, img, map);
	all->img = img;
	all->map = map;
	all->win = win;
	mlx_key_hook(win, &move, all);
	mlx_loop(win);
	free_map(map->map);
	free(map);
//	system("leaks so_long");
	return (0);
}

void	display_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		printf("%s", map->map[i]);
		i++;
	}
	printf("\n");
}
