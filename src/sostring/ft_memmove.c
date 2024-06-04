/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:10:38 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:04:53 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = -1;
	if (dest > src)
		while (n-- >= 1)
			((char *)dest)[n] = ((char *)src)[n];
	else
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
