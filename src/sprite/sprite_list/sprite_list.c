/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:10 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:23:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	sprite_list_add(t_so *so, t_sosprite_list *list, t_sosprite *sprite)
{
	t_sosprite_box	*box;

	box = so->malloc(so, sizeof(t_sosprite_box));
	box->current = sprite;
	box->next = list->first;
	list->first = box;
}

t_sosprite_list	*sprite_list_gets(t_so *so, char *name, t_sosprite_list *list)
{
	t_sosprite_list	*new_list;
	t_sosprite_box	*box;

	if (!list || !name)
		return (NULL);
	new_list = sprite_list(so);
	box = list->first;
	while (box->current)
	{
		if (so->libft->strncmp(box->current->construct->name, name, so->libft->strlen(name) - 1))
			sprite_list_add(so, new_list, box->current);
		box = box->next;
	}
	return (new_list);
}

t_sosprite	*sprite_list_get(t_so *so, char *name, t_sosprite_list *list)
{
	t_sosprite_box	*box;

	if (!list || !name)
		return (NULL);
	box = list->first;
	while (box->current)
	{
		if (!so->libft->strncmp(box->current->construct->name, name, so->libft->strlen(name) - 1))
			return (box->current);
		box = box->next;
	}
	return (NULL);
}

void	sprite_list_clear(t_so *so, t_sosprite_list *list)
{
	t_sosprite_box	*box;
	t_sosprite_box	*tmp;

	if (!list)
		return ;
	box = list->first;
	while (box)
	{
		tmp = box->next;
		so->free(so, box);
		box = tmp;
	}
	so->free(so, list);
	list = NULL;
}

t_sosprite_list	*sprite_list(t_so *so)
{
	t_sosprite_list	*list;

	list = so->malloc(so, sizeof(t_sosprite_list));
	list->first = so->malloc(so, sizeof(t_sosprite_box));
	list->first->current = NULL;
	list->first->next = NULL;
	return (list);
}