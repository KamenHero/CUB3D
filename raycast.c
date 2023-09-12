/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:41 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/12 14:52:22 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	draw_line1(t_img *img, int x0, int y0, int x1, int y1, int color) 
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int steps;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else 
		steps = abs(dy);
		
	if (steps == 0)
		return; // Avoid division by zero

	double	xInc = dx / (double)steps;
	double	yInc = dy / (double)steps;
	double	x = x0;
	double	y = y0;

	int i = 0;
	while (i <= steps) 
	{
		if (x < 0 || x > (img->s_wide ) ||
		y < 0 || y > (img->s_hight))
		return ;
		// printf("%f %f\n\n\n", x, y);
		pixel_put(img, (int)x, (int)y, color);
		x += xInc;
		y += yInc;
		i++;
	}
}


// void cast_ray(t_img *data)
// {
// 	double x = data->x;
// 	double y = data->y;
// 	while (!has_wall(data, x, y))
// 	{
// 		x += cos(data->ray->ray_angel);
// 		y -= sin(data->ray->ray_angel);
// 	}
// 	draw_line1(data, data->x, data->y, x, y, 0);
// }

void	ray_comp(t_img *img, double h_dis, double v_dis)
{
	if (h_dis > v_dis)
	{
		img->ray->x = img->ray->vwallhitx;
		img->ray->y = img->ray->vwallhity;
		img->ray->dis = v_dis;
	}
	else
	{
		img->ray->x = img->ray->hwallhitx;
		img->ray->y = img->ray->hwallhity;
		img->ray->dis = h_dis;
	}
}

void	horzintal_inter(t_img *img)
{
	double	xstep;
	double	ystep;
	double	xinter;
	double	yinter;

	yinter = (floor)(img->y / (64 )) * 64 ;
	if (sin(img->ray->ray_angel) < 0)//facing down
		yinter += 64;
	xinter = img->x + ((img->y - yinter) / tan(img->ray->ray_angel));
	ystep = 64;
	if (sin(img->ray->ray_angel)> 0)//facing up
		ystep *= -1;
	xstep = (64) / tan(img->ray->ray_angel);
	if (cos(img->ray->ray_angel) < 0 && xstep > 0)
	 	xstep *= -1;
	if (cos(img->ray->ray_angel) > 0 && xstep < 0)
	 	xstep *= -1;
	while (yinter < img->s_hight && xinter < img->s_wide)
	{
		// if (img->map[(int)yinter][(int)xinter] == '1')
		// 	break ;
		if (sin(img->ray->ray_angel) < 0)
		{
			if (has_wall(img, yinter,xinter ))
				break ;
		}
		 else if ((sin(img->ray->ray_angel) > 0))
		 {
			if (has_wall(img, yinter - 1,xinter ))
				break ;
		 }
		xinter += xstep;
		yinter += ystep;
	}
	img->ray->hwallhitx = xinter;
	img->ray->hwallhity = yinter;
	// printf("********%d %d \n\n", (int)(xinter / 64), (int)(yinter / 64));
	//draw_line1(img,img->x, img->y, xinter, yinter, 0);
}

void	vertical_inter(t_img *img)
{
	double	xstep;
	double	ystep;
	double	xinter;
	double	yinter;

	xinter = ((floor)(img->x / (64)) * (64));
	//printf("===%f\n", img->ray->ray_angel);
	if (cos(img->ray->ray_angel) >= 0)//facing righ
		xinter +=  64;
	yinter = img->y + ((img->x - xinter) * tan(img->ray->ray_angel));
	xstep = 64;
	if (cos(img->ray->ray_angel) < 0)//facing left
		xstep *= -1;
	ystep = (64) * tan(img->ray->ray_angel);
	if (sin(img->ray->ray_angel) >= 0 && ystep > 0)
	 	ystep *= -1;
	if (sin(img->ray->ray_angel) < 0 && ystep < 0)
	 	ystep *= -1;
	while (yinter < img->s_hight && xinter < img->s_wide)
	{
		 if (cos(img->ray->ray_angel) < 0)
		 {
			if (has_wall(img, yinter  ,xinter-1 ))
				break;
		}
		 else if ((cos(img->ray->ray_angel) > 0))
		 {
			if (has_wall(img, yinter ,xinter))
				break;
		 }
		xinter += xstep;
		yinter += ystep;
	}
	img->ray->vwallhitx = xinter;
	img->ray->vwallhity = yinter;
	// printf("********%d %d \n\n", (int)(xinter / 64), (int)(yinter / 64));
	//img->ray->vwallhitx = xinter;
	//draw_line1(img,img->x, img->y, xinter, yinter, 0xFFFFFF);
}

void    raycast(t_img *img)
{
	int	i;

	img->ray->ray_angel = img->angel +  (img->fov / 2);
	//printf("%f %f\n", img->angel, img->fov / 2);
	i = 0;
	int	j  = 0;
	int v = 0;
	while (j < img->s_hight)
	{
		v = 0;
		while (v < img->s_wide)
		{
			pixel_put(img, v, j, 0);
			v++;
		}
		j++;
	}
	while (i < img->s_wide)
	{
		if (img->ray->ray_angel < 0)
			img->ray->ray_angel += (2 * M_PI);
		if (img->ray->ray_angel > (2 * M_PI))
			img->ray->ray_angel -= (2 * M_PI);
		horzintal_inter(img);
		vertical_inter(img);
		ray_comp(img, distancepoints(img->x, img->y, img->ray->hwallhitx, img->ray->hwallhity), distancepoints(img->x, img->y, img->ray->vwallhitx, img->ray->vwallhity));
		draw_3d_line(img, i);
		img->ray->ray_angel -= img->fov / img->s_wide;
		i++;
	}
}
