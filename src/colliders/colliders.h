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

#ifndef COLLIDERS_H
# define COLLIDERS_H

# include <so/all.h>

void	sonew_collider(t_so *so);
void	collider_list_add(t_so *so, t_sosprite *sprite, int enabled,
			int (*callback)());
void	so_move_and_check(t_so *so, t_sovec2 vec2, t_sosprite *sprite);
int		is_inside(t_sovec2 A, t_sosize A_size, t_sovec2 B, t_sosize B_size);
void	so_vec2_add(t_so *so, t_sovec2 *dest, t_sovec2 vec2);
int		so_collider_call_callback(t_so *so, t_socollider *collider,
			t_socollider *sprite);
void	so_move_and_check(t_so *so, t_sovec2 vec2, t_sosprite *sprite);

#endif
