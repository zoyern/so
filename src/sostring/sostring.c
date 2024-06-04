/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:23:38 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:06:17 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

int	sonew_sostring(t_solibft *solibft)
{
	if (!solibft)
		return (1);
	solibft->bzero = ft_bzero;
	solibft->memchr = ft_memchr;
	solibft->memcmp = ft_memcmp;
	solibft->memcpy = ft_memcpy;
	solibft->memmove = ft_memmove;
	solibft->memset = ft_memset;
	solibft->split = ft_split;
	solibft->strchr = ft_strchr;
	solibft->strdup = ft_strdup;
	solibft->striteri = ft_striteri;
	solibft->strjoin = ft_strjoin;
	solibft->strlcat = ft_strlcat;
	solibft->strlcpy = ft_strlcpy;
	solibft->strlen = ft_strlen;
	solibft->strmapi = ft_strmapi;
	solibft->strmcat = ft_strmcat;
	solibft->strncmp = ft_strncmp;
	solibft->strnstr = ft_strnstr;
	solibft->strrchr = ft_strrchr;
	solibft->strtrim = ft_strtrim;
	solibft->substr = ft_substr;
	return (0);
}
