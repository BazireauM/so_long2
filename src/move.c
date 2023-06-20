/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:19:20 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/20 16:56:49 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_map(t_map *map);

void	move(mlx_key_data_t keydata, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
		printf("up\n");
	if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
		printf("down\n");
	if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
		printf("right\n");
	if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
		printf("left\n");
}
