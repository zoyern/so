/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sostdio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:58:53 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:03:14 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

int	sonew_stdio(t_solibft *solibft)
{
	if (!solibft)
		return (1);
	solibft->putchar = ft_putchar_fd;
	solibft->putendl = ft_putendl_fd;
	solibft->putnbr = ft_putnbr_fd;
	solibft->putstr = ft_putstr_fd;
	return (0);
}
