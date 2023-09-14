/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:40:42 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/14 16:36:21 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"


void	texture(t_img *img, int i,   float line_hight, float start, int y_tex)
{
	int	xoff;
	float	yoff;
	float	fin;

	 if (img->hitwas == 1)//vertical
	{
		xoff = (int)((img->ray->y / 20) * 20) % 20;
		// printf("%f**\n", xoff);
	}
	 else
	{
		xoff = (int)((img->ray->x / 20) * 20) % 20;
		// printf("%f**\n", xoff);
		//printf("%f**", fmod(img->ray->x, 20) / 20);
	}
	// fin = (20 * yoff) + xoff;
	// xoff = i * * img->xpm_no.bits_per_pixel / 8
	//yoff = ((float)(img->y3d - start) / (img->endy - start)) * 20;
	// int a = img->xpm_no.size_line;
	// float b = img->xpm_no.bits_per_pixel / 8;
	// float x = 0,y = 0;
	// int x1 = 0,y1 = 0;
	// while (x< 20){
	// 	y =0;
	// 	y1 = 0;
	// 	while (y< 20){
	// 		pixel_put(img, x1, y1, *((unsigned int*)(img->xpm_no.dir + (int)(((int)y*a)+((int)x*b)))));
	// 		y += 0.; 
	// 		y1++;
	// 	}
	// 	x += 0.5;
	// 	x1++;
	// }
	fin = (y_tex * img->xpm_no.size_line) + (xoff * (img->xpm_no.bits_per_pixel / 8));
	pixel_put(img, i, (int)img->y3d, *((unsigned int*)(img->xpm_no.dir + (int)fin))); 
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
		pixel_put(img, i ,j , 0x274e13);
    j = img->endy;
    while (j < img->s_hight)
    {
        pixel_put(img, i ,j , 0x274e13);
        j++;
    }
	float ygrid = 20 / line_height;
	float y_tex = 0;
	if (line_height > img->s_hight)
		y_tex = ygrid  * (line_height - img->s_hight) / 2;
	 while (img->y3d < img->endy)
	 {
		//pixel_put(img, i ,(int)img->y3d , 0xFFFFFF);
		texture(img, i,  line_height, start, y_tex); 
		y_tex += ygrid; 
		img->y3d++;
	 }
}