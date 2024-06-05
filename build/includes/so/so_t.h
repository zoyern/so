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


typedef struct s_sofuncs
{
	int	(*sostart)(t_so *so, void *data);
	int	(*soupdate)(t_so *so, void *data);
	int	(*soquit)(t_so *so, void *data);
}	t_sofuncs;

typedef struct s_so
{
	t_solib		*solib;
	void		*mlx;
	void		*display;
	int			(*print)(const char *str, ...);
	int			(*start)(t_solib *solib, void *data, t_sofuncs *funcs);
	int			(*close)(t_so *so, int state);
	t_sofuncs	*(*init)(t_solib *solib, int (*start)(t_so *so, void *data), int (*update)(t_so *so, void *data), int (*quit)(t_so *so, void *data));
	
}	t_so;

#endif