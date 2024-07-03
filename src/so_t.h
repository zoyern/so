/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_t.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:27:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 17:45:02 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_T_H
# define SO_T_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <sotypes.h>
# include <solibft.h>
# include <so.h>

typedef struct s_so			t_so;
typedef struct s_sofuncs	t_sofuncs;
typedef struct s_sokeys		t_sokeys;
typedef struct s_sovec2		t_sovec2;

typedef struct s_sovec2 {
	float	x;
	float	y;
}	t_sovec2;

typedef struct s_sosize {
	int	width;
	int	height;
}	t_sosize;

typedef struct s_sotransform {
	t_sovec2	*origin;
	t_sosize	*size;
}	t_sotransform;

typedef struct s_soconstruct {
	char	*name;
	char	*args;
	int		enabled;
}	t_soconstruct;

typedef struct s_sosprite_data{
	char			*args;
	t_sosize		*size;
	char			*adress;
	void			*ptr;	
	int				bpp;
	int				endian;
	int				line_len;
} t_sosprite_data;

typedef struct s_sosprite{
	int				is_image;
	t_soconstruct	*construct;
	t_sotransform	*transform;
	t_sovec2		*ratio;
	t_sosprite_data	*origin;
	t_sosprite_data	*data;
} t_sosprite;

typedef struct s_sokeys
{
	t_sovec2	*mouse;
	int			keys[256];
	int			escape;
}	t_sokeys;

typedef struct s_sonew
{
	t_sosprite		*(*sprite)(t_so *so, t_soconstruct *construct, t_sotransform *transform);
	void			(*grid)(t_so *so, int width, int height);
}	t_sonew;

typedef struct s_sofuncs
{
	int	(*sostart)(t_so *so, void *data);
	int	(*soupdate)(t_so *so, void *data);
	int	(*soquit)(t_so *so, void *data);
}	t_sofuncs;

typedef struct s_sogrid
{
	int	width;
	int	height;
	int	raw;
	int	collum;
	t_sosprite ***area;
}	t_sogrid;

typedef struct s_so
{
	int				loop;
	t_solib			*solib;
	t_solibft		*libft;
	t_sokeys		*inputs;
	t_sofuncs		*funcs;
	t_somemory		*imgmemory;
	t_sonew			*new;
	t_sosprite		*area;
	t_sogrid		*grid;
	void			*mlx;
	void			*window;
	void			*data;
	char			*name;
	t_sosize		*canva;
	int				(*print)(const char *str, ...);
	void			*(*malloc)(t_so *so, size_t size);
	int				(*free)(t_so *solib, void *ptr);
	int				(*start)(t_solib *solib, void *data, t_sosize *size, t_sofuncs *funcs);
	int				(*close)(t_so *so, int state);
	t_sofuncs		*(*sofuncs)(t_solib *solib, int (*start)(), int (*update)(), int (*quit)());
	t_sosize		*(*size)(t_so *so, float width, float height);
	t_sovec2		*(*vec2)(t_so *so, float x, float y);
	t_sotransform	*(*transform)(t_so *so, t_sovec2 *vector2, t_sosize *size);
	t_soconstruct	*(*construct)(t_so *so, char *name, char *args, int enabled);

}	t_so;

#endif