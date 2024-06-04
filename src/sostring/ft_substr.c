/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:14:48 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:05:55 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

char	*ft_substr(t_solib *solib, char const *s, size_t start, size_t len)
{
	char	*t;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(solib, ""));
	i = ft_strlen(s + start);
	if (len > i)
		len = i;
	t = (char *)solib->malloc(solib, sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	ft_strlcpy(t, s + start, len + 1);
	return (t);
}
