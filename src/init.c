/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:53:26 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:53:27 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env		*init_env(char **argv)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->w = (1600 / 3) * 2;
	env->h = (1200 / 3) * 2;
	env->hmap = ft_atoi(argv[1]);
	env->wmap = ft_atoi(argv[2]);
	env->mlx = mlx_init();
	env->map = init_map(env->hmap, env->wmap);
	env->img = init_image(env, env->w, env->h);
	env->win = mlx_new_window(env->mlx, env->w, env->h, " - W - O - L - F - ");
	env->player = init_player(env);
	create_minimap(env);
	env->u = 0;
	draw(env);
	return (env);
}

void		init_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 0, key_press_hook, env);
}
