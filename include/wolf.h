/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:52:53 by aramon            #+#    #+#             */
/*   Updated: 2017/06/29 02:52:58 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "math.h"
# include "stdio.h"
# include "stdlib.h"
# include "time.h"

# define TEX_MAP_SIZE 20
# define CNORTH 0xAA1FFF
# define CEAST  0x95B200
# define CWEST  0xFF6819
# define CSOUTH 0x00B2AE

typedef struct	s_map
{
	int			w;
	int			h;
	int			**content;
}				t_map;

typedef struct	s_image
{
	int			w;
	int			h;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			size;
	int			ed;
}				t_image;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_player
{
	double		x;
	double		y;
	t_vector	dir;
	t_vector	pos;
}				t_player;

typedef struct	s_cast
{
	int			mapx;
	int			mapy;
	double		sidex;
	double		sidey;
	double		deltax;
	double		deltay;
	int			stepx;
	int			stepy;
	double		wall;
}				t_cast;

typedef struct	s_ray
{
	double		x;
	double		y;
	int			side;
	double		dist;
	int			height;
	t_image		*tex;
	int			tex_x;
	double		fx;
	double		fy;
}				t_ray;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*minimap_win;
	t_image		*img;
	t_image		*minimap_img;
	int			w;
	int			h;
	int			u;
	t_map		*map;
	int			hmap;
	int			wmap;
	t_player	*player;
	int			a;
}				t_env;

t_env			*init_env(char **argv);
int				loop_hook(t_env *env);
void			init_hooks(t_env *env);
void			put_pixel_to_img(t_image *img, int x, int y, int color);
t_image			*init_image(t_env *env, int w, int h);
t_map			*init_map(int hmap, int wmap);
int				expose(t_env *env);
void			draw(t_env *env);
void			draw_debug(t_env *env);
int				key_press_hook(int keycode, t_env *env);
void			move(t_env *env, int keycode);
void			rotate(t_vector *v, float a);
void			rotate_player(t_player *p, int keycode);
t_player		*init_pos(t_env *env, t_player *p);
t_player		*init_player(t_env *env);
int				check_pos(t_env *env, int y, int x);
int				cast(t_env *env, t_ray *ray, t_player *player);
int				check_hit(t_env *env, t_ray *ray, t_cast *cast);
void			draw_floor(t_env *env);
void			use_img(t_env *env);
void			use_img_minimap(t_env *env);
int				check_arg(char **argv);
void			usage(void);
void			display_player_minimap(t_env *env);
void			display_minimap(t_env *env);
void			create_minimap(t_env *env);
void			draw_square(t_env *env, t_vector v, int size, int color);
int				**create_maze(int hmap, int wmap, int **tmp);
int				get_color(t_ray *r, t_cast c);
void			draw_column(t_env *env, t_ray *r, int x, int color);

#endif
