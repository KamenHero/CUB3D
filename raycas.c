/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:41 by onaciri           #+#    #+#             */
/*   Updated: 2023/08/22 18:52:38 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void    raycast(t_img *img)
{
    double l_angel;
    double  atan;

    l_angel = img->angel;
    atan = 1 / tan(l_angel);
    if (l_angel > M_PI)//loking down
    {
        
    }
}