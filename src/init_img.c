/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:44:32 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/19 16:05:55 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*init_img(mlx_t *win)
{
	t_img	*img;

	img = malloc(sizeof(t_img) * 1);
	if (img == NULL)
		return (NULL);
	img->doorT = mlx_load_png("sprite/Door.png");
	img->door = mlx_new_image(win, 20, 20);
	img->door = mlx_texture_to_image(win, img->doorT);
	img->foxT = mlx_load_png("sprite/Fox.png");
	img->fox = mlx_new_image(win, 20, 20);
	img->fox = mlx_texture_to_image(win, img->foxT);
	img->wallT = mlx_load_png("sprite/Wall.png");
	img->wall = mlx_new_image(win, 20, 20);
	img->wall = mlx_texture_to_image(win, img->wallT);
	img->itemT = mlx_load_png("sprite/Item.png");
	img->item = mlx_new_image(win, 20, 20);
	img->item = mlx_texture_to_image(win, img->itemT);
	img->noneT = mlx_load_png("sprite/None.png");
	img->none = mlx_new_image(win, 20, 20);
	img->none = mlx_texture_to_image(win, img->noneT);
	return (img);
}

void	first_print(mlx_t *win, t_img *img, t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < lenx)
	{
		while (y < leny)
		{
			y++;
		}
		x++;
	}
}
