/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:53:10 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:53:12 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

unsigned int			smog(unsigned int c, double d)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	d = 7 / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (r > 0)
		r = r - (r * d);
	if (g > 0)
		g = g - (g * d);
	if (b > 0)
		b = b - (b * d);
	return ((r << 16) + (g << 8) + b);
}

void					draw_square(t_env *env, t_vector v, int size, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_pixel_put(env->mlx, env->minimap_win, x + v.x, y + v.y, color);
			x++;
		}
		y++;
	}
}

void					draw_column(t_env *env, t_ray *r, int x, int color)
{
	int		y;
	int		start;
	int		end;

	y = 0;
	start = (env->h - r->height) / 2;
	end = start + r->height;
	if (start < 0)
		start = 0;
	while (y < start)
		put_pixel_to_img(env->img, x, y++, 0x000000);
	if (end > env->h - 1)
		end = env->h - 1;
	y = start;
	while (y < end)
	{
		put_pixel_to_img(env->img, x, y, smog(color, r->dist));
		y++;
	}
	while (y < env->h)
		put_pixel_to_img(env->img, x, y++, 0x000000);
}

void					draw(t_env *env)
{
	int					x;
	t_ray				ray;
	double				camx;
	unsigned int		c;

	x = 0;
	c = 0;
	while (x < env->w)
	{
		camx = 2.0f * x / env->w - 1.0f;
		ray.x = env->player->dir.x + env->player->pos.x * camx;
		ray.y = env->player->dir.y + env->player->pos.y * camx;
		c = cast(env, &ray, env->player);
		draw_column(env, &ray, x, c);
		x++;
	}
	display_minimap(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}
