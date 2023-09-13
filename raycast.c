/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:41 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/13 15:58:57 by onaciri          ###   ########.fr       */
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

	float	xInc = dx / (float)steps;
	float	yInc = dy / (float)steps;
	float	x = x0;
	float	y = y0;

	int i = 0;
	while (i <= steps) 
	{
		if (x < 0 || x > (img->s_wide  ) ||
		y < 0 || y > (img->s_hight  ))
		return ;
		// printf("%f %f\n\n\n", x, y);
		pixel_put(img, round(x), round(y), color);
		x += xInc;
		y += yInc;
		i++;
	}
}


// void cast_ray(t_img *data)
// {
// 	float x = data->x;
// 	float y = data->y;
// 	while (!has_wall(data, x, y))
// 	{
// 		x += cos(data->ray->ray_angel);
// 		y -= sin(data->ray->ray_angel);
// 	}
// 	draw_line1(data, data->x, data->y, x, y, 0);
// }20

void	ray_comp(t_img *img, float h_dis, float v_dis)
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
	float	xstep;
	float	ystep;
	float	xinter;
	float	yinter;

	yinter = (int)(img->y / (20)) * 20;
	if (sin(img->ray->ray_angel) < 0)//facing down
		yinter += 20  ;
	xinter = img->x + ((img->y - yinter) / tan(img->ray->ray_angel));
	ystep = 20;
	if (sin(img->ray->ray_angel)> 0)//facing up
		ystep *= -1;
	xstep = (20) / tan(img->ray->ray_angel);
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
			if (has_wall(img, yinter ,xinter ))
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
	// printf("********%d %d \n\n", (int)(xinter / 20), (int)(yinter / 20));
	//draw_line1(img,img->x, img->y, xinter, yinter, 0);
}

void	vertical_inter(t_img *img)
{
	float	xstep;
	float	ystep;
	float	xinter;
	float	yinter;

	xinter = ((int)(img->x / (20  )) * (20  ));
//	printf("===%f\n", img->ray->ray_angel);
	if (cos(img->ray->ray_angel) >= 0)//facing righ
		xinter +=   20;
	yinter = img->y + ((img->x - xinter) * tan(img->ray->ray_angel));
	xstep = 20  ;
	if (cos(img->ray->ray_angel) < 0)//facing left
		xstep *= -1;
	ystep = (20  ) * tan(img->ray->ray_angel);
	if (sin(img->ray->ray_angel) >= 0 && ystep > 0)
	 	ystep *= -1;
	if (sin(img->ray->ray_angel) < 0 && ystep < 0)
	 	ystep *= -1;
	while (yinter < img->s_hight && xinter < img->s_wide)
	{
		 if (cos(img->ray->ray_angel) < 0)
		 {
			if (has_wall(img, yinter  ,xinter - 1 ))
				break;
		}
		 else if ((cos(img->ray->ray_angel) > 0))
		 {
			if (has_wall(img, yinter ,xinter  ))
				break;
		 }
		xinter += xstep;
		yinter += ystep;
	}
	img->ray->vwallhitx = xinter;
	img->ray->vwallhity = yinter;
	// printf("********%d %d \n\n", (int)(xinter / 20), (int)(yinter / 20));
	//img->ray->vwallhitx = xinter;
	//draw_line1(img,img->x, img->y, xinter, yinter, 0xFFFFFF);
}

void    raycast(t_img *img)
{
	int	i;

	img->ray->ray_angel = img->angel -  (img->fov / 2);
	//printf("%f %f\n", img->angel, img->fov / 2);
	i = 0;
	while (i < img->s_wide)
	{
		if (img->ray->ray_angel < 0)
			img->ray->ray_angel += (2 * M_PI);
		if (img->ray->ray_angel >= (2 * M_PI))
			img->ray->ray_angel -= (2 * M_PI);
		horzintal_inter(img);
		vertical_inter(img);
		ray_comp(img, distancepoints(img->x, img->y, img->ray->hwallhitx, img->ray->hwallhity), distancepoints(img->x, img->y, img->ray->vwallhitx, img->ray->vwallhity));
	//	draw_line1(img,img->x, img->y, img->ray->x, img->ray->y, 0xFFFFFF);
		draw_3d_line(img, i);
		img->ray->ray_angel += img->fov / img->s_wide;
		i++;
	}
}
