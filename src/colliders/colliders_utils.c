/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colliders_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:10:13 by marvin            #+#    #+#             */
/*   Updated: 2024/07/08 20:10:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

int is_inside(t_sovec2 A, t_sosize A_size, t_sovec2 B, t_sosize B_size)
{
    return (B.x + B_size.width >= A.x + 5 &&
            B.y + B_size.height >= A.y +  5 &&
            B.x <= A.x + A_size.width - 5 &&
            B.y <= A.y + A_size.height - 5);
}