/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:17:55 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:05:06 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = dst_len;
	if (size <= dst_len || size < 1)
		return (src_len + size);
	dst += dst_len;
	while (*src && i++ < size - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
