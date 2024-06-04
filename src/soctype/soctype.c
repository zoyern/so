/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soctype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:23:38 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:02:18 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

int	sonew_ctype(t_solibft *solibft)
{
	if (!solibft)
		return (1);
	solibft->isalnum = ft_isalnum;
	solibft->isalpha = ft_isalpha;
	solibft->isascii = ft_isascii;
	solibft->isdigit = ft_isdigit;
	solibft->isprint = ft_isprint;
	solibft->tolower = ft_tolower;
	solibft->toupper = ft_toupper;
	return (0);
}
