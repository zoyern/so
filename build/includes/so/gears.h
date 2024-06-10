/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:22:15 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:22:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEARS_H
# define GEARS_H

# include <so/all.h>

int 		so_close(t_so *so, int state);
int			 so_close_update(t_so *so, int state);
t_sofuncs	*sonew_sofuncs(t_solib *solib, int (*start)(), int (*update)(), int (*quit)());

#endif
