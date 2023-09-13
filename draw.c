/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:40:42 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/13 15:52:48 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void    draw_3d_line(t_img *img, int i)
{
    double   line_height;
    int     j;

    img->dis_plane = (img->s_wide / 2);
    img->ray->dis =  cos(img->angel - img->ray->ray_angel) * img->ray->dis;
    line_height = ((20 / img->ray->dis)) * img->dis_plane;
    img->y3d = (int)(img->s_hight / 2) - (line_height / 2);
    img->endy = (int)(img->s_hight / 2) + (line_height / 2);
    if (img->y3d < 0)
        img->y3d = 0;
    if (img->endy > img->s_hight)
    {    
		img->endy = img->s_hight;
	}
    j = 0;
    while (j <= img->y3d)
    {
        pixel_put(img, i ,j , 0x274e13);
        j++;
    }
    j = img->endy;
    while (j < img->s_hight)
    {
        pixel_put(img, i ,j , 0x274e13);
        j++;
    }
	while (img->y3d < img->endy)
	{
		//printf("%f %f %f %f %f\n\n", img->y3d, img->endy, img->ray->dis, img->dis_plane, line_height);
		pixel_put(img, i ,(int)img->y3d , 0xFFFFFF);
		img->y3d++;
	}
}