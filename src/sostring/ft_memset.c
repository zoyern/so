/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:59:27 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:04:54 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

void	*ft_memset(void *dst, int c, size_t n)
{
	while (n-- > 0)
		((unsigned char *)dst)[n] = (unsigned char)c;
	return (dst);
}
