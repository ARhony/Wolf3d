/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:53:43 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:53:45 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			**create_maze(int hmap, int wmap, int **tmp)
{
	int			i;
	int			j;
	time_t		t;

	i = 0;
	srand((unsigned)time(&t));
	while (i < hmap)
	{
		j = 0;
		while (j < wmap)
		{
			if (((rand() % 100) > 75 || ((j == 0 || j == wmap - 1) ||
				(i == 0 || i == hmap - 1))) && (i != 1 || j != 1))
				tmp[i][j] = 1;
			j++;
		}
		i++;
	}
	return (tmp);
}

t_map		*init_map(int hmap, int wmap)
{
	int			i;
	int			j;
	t_map		*map;
	int			**tmp;
	int			size;

	i = 0;
	size = (hmap > wmap ? hmap : wmap);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(tmp = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	while (i < size)
	{
		j = 0;
		tmp[i] = (int*)malloc(sizeof(int) * size);
		while (j < size)
			tmp[i][j++] = 0;
		i++;
	}
	map->content = create_maze(hmap, wmap, tmp);
	map->w = wmap;
	map->h = hmap;
	return (map);
}
