/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:53:38 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:53:39 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	hook_close(t_env *env)
{
	(void)env;
	exit(EXIT_SUCCESS);
	return (0);
}

void		usage(void)
{
	ft_putendl("binary + height + width");
	ft_putendl("./wolf | 3 <-> 50 | 3 <-> 50");
	exit(0);
}

int			check_arg(char **argv)
{
	int		tmp_h;
	int		tmp_w;

	tmp_h = ft_atoi(argv[1]);
	tmp_w = ft_atoi(argv[2]);
	if ((tmp_h > 2 && tmp_h <= 50) && (tmp_w > 2 && tmp_w <= 50))
		return (1);
	else
		return (0);
}

int			main(int argc, char **argv)
{
	t_env		*env;

	env = NULL;
	if (argc == 3 && check_arg(argv))
		env = init_env(argv);
	else
		usage();
	init_hooks(env);
	mlx_hook(env->win, 17, 1L << 0, hook_close, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
