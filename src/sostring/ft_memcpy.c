/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:14:17 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:04:52 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*t;

	if (dest == src)
		return (0);
	t = dest;
	while (n--)
		*t++ = *(unsigned char *)src++;
	return (dest);
}
