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

typedef struct s_sosprite_data{
	int				is_image;
	t_sotransform	*transform;
	char			*adress;
	void			*ptr;	
	int				bpp;
	int				endian;
	int				line_len;
} t_sosprite_data;

typedef struct s_sosprite{
	t_solib_construct	*construct;
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
	int	(*sprite)(t_so *so, char *path);
}	t_sonew;

typedef struct s_sofuncs
{
	int	(*sostart)();
	int	(*soupdate)();
	int	(*soquit)();
}	t_sofuncs;

typedef struct s_so
{
	int			loop;
	t_solib		*solib;
	t_solibft	*libft;
	t_sokeys	*inputs;
	t_sofuncs	*funcs;
	t_sonew		*new;
	void		*mlx;
	void		*window;
	void		*data;
	char		*name;
	int			width;
	int			height;
	int			(*print)(const char *str, ...);
	void		*(*malloc)(t_solib *solib, size_t size);
	int			(*free)(t_solib *solib, void *ptr);
	int			(*start)(t_solib *solib, void *data, t_sofuncs *funcs);
	int			(*close)(t_so *so, int state);
	t_sofuncs	*(*sofuncs)(t_solib *solib, int (*start)(), int (*update)(), int (*quit)());
	
}	t_so;

#endif