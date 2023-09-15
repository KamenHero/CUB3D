/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:40:42 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/15 10:11:54 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"


void	texture(t_img *img, int i,   float line_hight, float start, int y_tex)
{
	int		xoff;
	float	yoff;
	float	fin;

	if (img->hitwas == 1)
		xoff = (int)((img->ray->y / 20) * 64) % 64;
	 else
		xoff = (int)((img->ray->x / 20) * 64) % 64;
	fin = (y_tex * img->texUse.size_line) + (xoff * (img->texUse.bits_per_pixel / 8));
	pixel_put(img, i, (int)img->y3d, *((unsigned int*)(img->texUse.dir + (int)fin))); 
}


void    draw_3d_line(t_img *img, int i)
{
    double   line_height;
    int     j;
	double start;

    img->dis_plane = (img->s_wide / 2);
    img->ray->dis =  cos(img->angel - img->ray->ray_angel) * img->ray->dis;
    line_height = ((20 / img->ray->dis)) * img->dis_plane;
    img->y3d = (int)(img->s_hight / 2) - (line_height / 2);
    img->endy = (int)(img->s_hight / 2) + (line_height / 2);
	if (img->y3d < 0)
        img->y3d = 0;
    if (img->endy > img->s_hight)
		img->endy = img->s_hight;
    start = img->y3d;
    j = -1;
    while (++j <= img->y3d)
		pixel_put(img, i ,j , img->data->fc.c);
    j = img->endy;
    while (j < img->s_hight)
    {
        pixel_put(img, i ,j , img->data->fc.f);
        j++;
    }
	float ygrid = 64 / line_height;
	float y_tex = 0;
	if (line_height > img->s_hight)
		y_tex = ygrid  * (line_height - img->s_hight) / 2;
	 while (img->y3d < img->endy)
	 {
		//printf("%f\n", img->angel);
		if (img->ray->ray_angel > M_PI / 3 && img->ray->ray_angel <= 3 * M_PI / 4)
		{
			img->texUse = img->xpm_no;
			img->texUse.dir = img->xpm_no.dir;
		}
		else if (img->ray->ray_angel > 3 * M_PI / 4 && img->ray->ray_angel <= 5 * M_PI / 4)
		{
			img->texUse = img->xpm_we;
			img->texUse.dir = img->xpm_we.dir;
		}
		else if (img->ray->ray_angel > 5 * M_PI / 4 && img->ray->ray_angel <= 11 * M_PI / 6)
		{
			img->texUse = img->xpm_so;
			img->texUse.dir = img->xpm_so.dir;
		}
		else
		{
			img->texUse = img->xpm_ea;
			img->texUse.dir = img->xpm_ea.dir;
		}
		texture(img, i,  line_height, start, y_tex); 
		y_tex += ygrid; 
		img->y3d++;
	 }
}