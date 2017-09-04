/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:53:19 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:53:21 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		put_pixel_to_img(t_image *img, int x, int y, int color)
{
	int			i;

	if (x > 0 && y > 0 && x < img->w && y < img->h)
	{
		i = (x * (img->bpp / 8)) + (y * img->size);
		img->pixel_img[i] = color;
		img->pixel_img[++i] = color >> 8;
		img->pixel_img[++i] = color >> 16;
	}
}

t_image		*init_image(t_env *env, int w, int h)
{
	t_image		*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->img = mlx_new_image(env->mlx, env->w, env->h);
	image->w = w;
	image->h = h;
	image->size = w;
	image->pixel_img = mlx_get_data_addr(image->img, &(image->bpp),
		&(image->size), &(image->ed));
	return (image);
}
