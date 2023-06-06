/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:42:20 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/06 13:08:57 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct	s_map
{
	int		lenx;
	int		leny;
	char	**map;
}	t_map;

//	test.c

int		test_name_file(char *s);

//	parssing.c (full)

char	**parssing(char *map);
char	**append_final(char **final, char *tmp);
char	**append_final2(char **final, char *tmp, char **tmp2, int i);
int		free_all_final(char **final);
int		len_char_char(char **final);

//	free.c

void	free_map(char **map);
void	free_struct_map(t_map *map);

#endif
