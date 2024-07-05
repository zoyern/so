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

#ifndef HOOKS_H
# define HOOKS_H

# include <so/all.h>

enum e_solib_event
{
	KeyPress = 2,
	KeyRelease,
	ButtonPress,
	ButtonRelease,
	MotionNotify,
	EnterNotify,
	LeaveNotify,
	FocusIn,
	FocusOut,
	KeymapNotify,
	Expose,
	GraphicsExpose,
	NoExpose,
	VisibilityNotify,
	CreateNotify,
	DestroyNotify,
	UnmapNotify,
	MapNotify,
	MapRequest,
	ReparentNotify,
	ConfigureNotify,
	ConfigureRequest,
	GravityNotify,
	ResizeRequest,
	CirculateNotify,
	CirculateRequest,
	PropertyNotify,
	SelectionClear,
	SelectionRequest,
	SelectionNotify,
	ColormapNotify,
	ClientMessage,
	MappingNotify,
	GenericEvent,
	LASTEvent,
};

enum e_solib_mask
{
	NoEventMask = 0L,
	KeyPressMask = (1L<<0),
	KeyReleaseMask = (1L<<1),
	ButtonPressMask = (1L<<2),
	ButtonReleaseMask = (1L<<3),
	EnterWindowMask = (1L<<4),
	LeaveWindowMask = (1L<<5),
	PointerMotionMask = (1L<<6),
	PointerMotionHintMask = (1L<<7),
	Button1MotionMask = (1L<<8),
	Button2MotionMask = (1L<<9),
	Button3MotionMask = (1L<<10),
	Button4MotionMask = (1L<<11),
	Button5MotionMask = (1L<<12),
	ButtonMotionMask = (1L<<13),
	KeymapStateMask = (1L<<14),
	ExposureMask = (1L<<15),
	VisibilityChangeMask = (1L<<16),
	StructureNotifyMask = (1L<<17),
	ResizeRedirectMask = (1L<<18),
	SubstructureNotifyMask = (1L<<19),
	SubstructureRedirectMask = (1L<<20),
	FocusChangeMask = (1L<<21),
	PropertyChangeMask = (1L<<22),
	ColormapChangeMask = (1L<<23),
	OwnerGrabButtonMask = (1L<<24),
};

void		so_hooks(t_so *so);
t_sokeys	*so_new_keys(t_solib *solib);
int			solib_key_press(int keycode, t_so *so);
int			solib_key_release(int keycode, t_so *so);

#endif
