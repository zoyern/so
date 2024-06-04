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
# include <sotypes.h>
# include <solibft.h>
# include <so.h>

typedef struct s_so
{
	void	*mlx;
	void	*display;
	int	(*start)(t_solib *solib);
	int	(*close)(t_solib *solib, int state);
}	t_so;

#endif