/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:41 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/16 12:39:15 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1280 || y >= 768)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ray_comp(t_img *img, float h_dis, float v_dis)
{
	if (h_dis > v_dis)
	{
		img->ray->x = img->ray->vx;
		img->ray->y = img->ray->vy;
		img->ray->dis = v_dis;
		img->hitwas = 1;
		if (cos(img->ray->ray_angel) >= 0)
			img->ray->look = 0;
		else
			img->ray->look = 1;
	}
	else
	{
		img->ray->x = img->ray->hx;
		img->ray->y = img->ray->hy;
		img->ray->dis = h_dis;
		img->hitwas = 2;
		if (sin(img->ray->ray_angel) >= 0)
			img->ray->look = 2;
		else
			img->ray->look = 3;
	}
}

void	horzintal_inter(t_img *img, float xstep, float ystep)
{
	img->ray->hy = (int)(img->y / 20) * 20;
	if (sin(img->ray->ray_angel) < 0)
		img->ray->hy += 20 ;
	img->ray->hx = img->x + ((img->y - img->ray->hy)
			/ tan(img->ray->ray_angel));
	ystep = 20;
	if (sin(img->ray->ray_angel) > 0)
		ystep *= -1;
	xstep = 20 / tan(img->ray->ray_angel);
	if (cos(img->ray->ray_angel) < 0 && xstep > 0)
		xstep *= -1;
	if (cos(img->ray->ray_angel) > 0 && xstep < 0)
		xstep *= -1;
	while (img->ray->hy < img->s_hight && img->ray->hx < img->s_wide)
	{
		if (has_wall(img, img->ray->hy, img->ray->hx))
			break ;
		else if ((sin(img->ray->ray_angel) > 0))
			if (has_wall(img, img->ray->hy - 1, img->ray->hx))
				break ;
		img->ray->hx += xstep;
		img->ray->hy += ystep;
	}
}

void	vertical_inter(t_img *img, float xstep, float ystep)
{
	img->ray->vx = ((int)(img->x / 20) * 20);
	if (cos(img->ray->ray_angel) >= 0)
		img->ray->vx += 20;
	img->ray->vy = img->y + ((img->x - img->ray->vx)
			* tan(img->ray->ray_angel));
	xstep = 20;
	if (cos(img->ray->ray_angel) < 0)
		xstep *= -1;
	ystep = 20 * tan(img->ray->ray_angel);
	if (sin(img->ray->ray_angel) >= 0 && ystep > 0)
		ystep *= -1;
	if (sin(img->ray->ray_angel) < 0 && ystep < 0)
		ystep *= -1;
	while (img->ray->vy < img->s_hight && img->ray->vx < img->s_wide)
	{
		if (cos(img->ray->ray_angel) < 0)
			if (has_wall(img, img->ray->vy, img->ray->vx - 1))
				break ;
		if (has_wall(img, img->ray->vy, img->ray->vx))
			break ;
		img->ray->vx += xstep;
		img->ray->vy += ystep;
	}
}

void	raycast(t_img *img)
{
	int	i;

	img->ray->ray_angel = img->angel - (img->fov / 2);
	i = 0;
	while (i < img->s_wide)
	{
		if (img->ray->ray_angel < 0)
			img->ray->ray_angel += (2 * M_PI);
		if (img->ray->ray_angel >= (2 * M_PI))
			img->ray->ray_angel -= (2 * M_PI);
		horzintal_inter(img, 0, 0);
		vertical_inter(img, 0, 0);
		ray_comp(img, distancepoints(img->x, img->y,
				img->ray->hx, img->ray->hy),
			distancepoints(img->x, img->y, img->ray->vx, img->ray->vy));
		draw_3d_line(img, i);
		img->ray->ray_angel += img->fov / img->s_wide;
		i++;
	}
}
