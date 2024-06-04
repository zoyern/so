/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:19:18 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:05:23 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

char	*ft_strtrim(t_solib *solib, char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*t;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strrchr(set, s1[end - 1]))
		end--;
	t = (char *)solib->malloc(solib, sizeof(char) * ((end - start) + 1));
	if (!t)
		return (NULL);
	while (start < end)
		t[i++] = s1[start++];
	t[i] = '\0';
	return (t);
}
