/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:54:34 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:54:38 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move(t_env *env, int keycode)
{
	double		dist;

	dist = (keycode == 125 ? -0.05 : 0.05);
	if (!check_pos(env, env->player->x + dist * env->player->dir.x,
				env->player->y))
		env->player->x += dist * env->player->dir.x;
	if (!check_pos(env, env->player->x,
				env->player->y + dist * env->player->dir.y))
		env->player->y += dist * env->player->dir.y;
}

void		rotate(t_vector *v, float a)
{
	double		xtmp;

	xtmp = v->x;
	v->x = v->x * cos(a) - v->y * sin(a);
	v->y = xtmp * sin(a) + v->y * cos(a);
}

void		rotate_player(t_player *p, int keycode)
{
	double		angle;

	angle = (keycode == 123 ? -2.0f : 2.0f) / 180.0f * M_PI;
	rotate(&p->dir, angle);
	rotate(&p->pos, angle);
}

t_player	*init_pos(t_env *env, t_player *p)
{
	int i;
	int j;

	i = 0;
	while (i < env->hmap)
	{
		j = 0;
		while (j < env->wmap)
		{
			if (check_pos(env, j, i) == 0)
				break ;
			j++;
		}
		i++;
	}
	p->x = 1 + 0.5f;
	p->y = 1 + 0.5f;
	return (p);
}

t_player	*init_player(t_env *env)
{
	t_player*p;

	p = (t_player*)malloc(sizeof(t_player));
	p = init_pos(env, p);
	p->dir.x = 1.0f;
	p->dir.y = 0.0f;
	p->pos.x = 0.0f;
	p->pos.y = 2.0f / 3.0f;
	return (p);
}
