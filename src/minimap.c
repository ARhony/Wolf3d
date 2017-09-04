/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:53:48 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:53:49 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		display_player_minimap(t_env *env)
{
	t_vector		v;

	v.x = env->player->x * 10;
	v.y = env->player->y * 10;
	draw_square(env, v, 15, 0xFF0000);
	v.x += env->player->dir.x;
	v.y += env->player->dir.y;
	draw_square(env, v, 10, 0xFF00);
}

void		display_minimap(t_env *env)
{
	int			x;
	int			y;
	t_vector	v;

	x = 0;
	y = 0;
	while (y < env->hmap)
	{
		x = 0;
		while (x < env->wmap)
		{
			v.y = y * 10;
			v.x = x * 10;
			if (check_pos(env, x, y))
				draw_square(env, v, 10, 0xFF0000);
			else
				draw_square(env, v, 10, 0xFFFFFF);
			x++;
		}
		y++;
	}
	display_player_minimap(env);
}

void		create_minimap(t_env *env)
{
	env->minimap_win = mlx_new_window(env->mlx, env->wmap * 10,
	env->hmap * 10, "Minimap");
	display_minimap(env);
}
