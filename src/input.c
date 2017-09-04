/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:53:31 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:53:32 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == 126 || keycode == 125)
		move(env, keycode);
	if (keycode == 123 || keycode == 124)
		rotate_player(env->player, keycode);
	env->u = 1;
	return (0);
}

int		expose(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	draw(env);
	return (0);
}

int		loop_hook(t_env *env)
{
	if (env->u)
		expose(env);
	env->u = 0;
	return (0);
}
