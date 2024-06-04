/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:15:12 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:04:59 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	if (*str == (unsigned char)c)
		return ((char *)str);
	if (!*str)
		return (0);
	return (ft_strchr(str + 1, c));
}
