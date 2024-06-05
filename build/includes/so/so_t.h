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

typedef struct s_sokeys
{
	t_sovec2	*mouse;
	int			keys[256];
}	t_sokeys;

typedef struct s_sofuncs
{
	int	(*sostart)();
	int	(*soupdate)();
	int	(*soquit)();
}	t_sofuncs;

typedef struct s_so
{
	t_solib		*solib;
	t_solibft	*libft;
	t_sokeys	*inputs;
	t_sofuncs	*funcs;
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
	t_sofuncs	*(*init)(t_solib *solib, int (*start)(), int (*update)(), int (*quit)());
	
}	t_so;

#endif