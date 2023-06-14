/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:48:28 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/14 16:28:15 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	display_map(t_map *map);

int	main(int argc, char *argv[])
{
	mlx_texture_t	*test;
	mlx_t		*win;
	t_map		*map;
	mlx_image_t	*img;

	if (argc != 2)
		return (0);
	if (test_name_file(argv[1]) == 1)
	{
		ft_printf("error files\n");
		return (0);
	}
	map = malloc(sizeof(t_map) * 1);
	map->map = parssing(argv[1]);
	printf("%d\n", test_map(map));
	display_map(map);
	free_map(map->map);
	free(map);
//	system("leaks so_long");
	printf("test : %d\n", map->lenx);
	printf("test : %d\n", map->leny);
	win = mlx_init(20 * map->lenx, 20 * map->leny, "so_long", 1);
	img = mlx_new_image(win, 20, 20);
	test = mlx_load_png("sprite/Wall.png");
	img = mlx_texture_to_image(win, test);
	mlx_image_to_window(win, img, 0, 0);
	mlx_loop(win);
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
