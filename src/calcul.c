/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 04:29:34 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 04:29:47 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int				check_pos(t_env *env, int x, int y)
{
	if (x < 0 || y < 0 || x > env->wmap - 1 || y > env->hmap - 1)
		return (0);
	return (env->map->content[y][x]);
}

int				get_color(t_ray *r, t_cast c)
{
	if (r->side == 1)
	{
		if ((c.stepx == -1 && c.stepy == -1) ||
			(c.stepx == 1 && c.stepy == -1))
			return (CNORTH);
		if ((c.stepx == -1 && c.stepy == 1) ||
			(c.stepx == 1 && c.stepy == 1))
			return (CSOUTH);
	}
	if ((c.stepx == -1 && c.stepy == -1) ||
			(c.stepx == -1 && c.stepy == 1))
		return (CWEST);
	return (CEAST);
}

int				check_hit(t_env *env, t_ray *ray, t_cast *cast)
{
	int check_hit;
	int block_view;

	check_hit = 0;
	block_view = -1;
	while (!check_hit && ++block_view < 30)
	{
		if (cast->sidex < cast->sidey)
		{
			cast->sidex += cast->deltax;
			cast->mapx += cast->stepx;
			ray->side = 0;
		}
		else
		{
			cast->sidey += cast->deltay;
			cast->mapy += cast->stepy;
			ray->side = 1;
		}
		if (cast->mapx < 0 || cast->mapy < 0 || cast->mapx >= env->wmap
				|| cast->mapy >= env->hmap)
			break ;
		check_hit = check_pos(env, cast->mapx, cast->mapy);
	}
	return (check_hit);
}

int				cast(t_env *env, t_ray *ray, t_player *p)
{
	t_cast			c;
	int				hit;

	c.mapx = (int)p->x;
	c.mapy = (int)p->y;
	c.deltax = sqrt((ray->y * ray->y) / (ray->x * ray->x) + 1);
	c.deltay = sqrt((ray->x * ray->x) / (ray->y * ray->y) + 1);
	c.stepx = (ray->x < 0 ? -1 : 1);
	c.stepy = (ray->y < 0 ? -1 : 1);
	c.sidex = (ray->x < 0 ? (p->x - c.mapx) * c.deltax :
			(c.mapx + 1.0 - p->x) * c.deltax);
	c.sidey = (ray->y < 0 ? (p->y - c.mapy) * c.deltay :
			(c.mapy + 1.0 - p->y) * c.deltay);
	ray->height = 0;
	if ((hit = check_hit(env, ray, &c)))
	{
		if (ray->side)
			ray->dist = (c.mapy - p->y + (1 - c.stepy) / 2) / ray->y;
		else
			ray->dist = (c.mapx - p->x + (1 - c.stepx) / 2) / ray->x;
		ray->height = floor(env->h / ray->dist);
	}
	return (get_color(ray, c));
}
