/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:17:19 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:05:05 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

char	*ft_strjoin(t_solib *solib, char const *s1, char const *s2)
{
	size_t	len;
	char	*t;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	t = (char *)solib->malloc(solib, sizeof(char) * (len + 1));
	if (!t)
		return (0);
	while (*s1)
		*t++ = *s1++;
	while (*s2)
		*t++ = *s2++;
	*t = '\0';
	return (t -= len);
}
