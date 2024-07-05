/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soimgmemory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:57:56 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 14:21:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOIMGMEMORY_H
# define SOIMGMEMORY_H

# include <so/all.h>

int				soimgnew_memory(t_so *so);
void			soimgmemory_show(t_solib *solib);
t_somemdata		*soimgmemory_remove(t_solib *solib, void *ptr);
void			soimgmemory_clear(t_solib *solib);
void			soimgmemory_add(t_solib *solib, void *ptr);
int				soimgfree(t_so *so, void *ptr);
#endif
