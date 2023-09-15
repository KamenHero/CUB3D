/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:41 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/14 19:49:05 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	ray_comp(t_img *img, float h_dis, float v_dis)
{
	if (h_dis > v_dis)
	{
		img->ray->x = img->ray->vwallhitx;
		img->ray->y = img->ray->vwallhity;
		img->ray->dis = v_dis;
		img->hitwas = 1;
	}
	else
	{
		img->ray->x = img->ray->hwallhitx;
		img->ray->y = img->ray->hwallhity;
		img->ray->dis = h_dis;
		img->hitwas = 2;
	}
}

void	horzintal_inter(t_img *img)
{
	float	xstep;
	float	ystep;

	img->ray->hwallhity = (int)(img->y / 20) * 20;
	if (sin(img->ray->ray_angel) < 0)
		img->ray->hwallhity += 20  ;
	img->ray->hwallhitx = img->x + ((img->y - img->ray->hwallhity) / tan(img->ray->ray_angel));
	ystep = 20;
	if (sin(img->ray->ray_angel)> 0)
		ystep *= -1;
	xstep = 20 / tan(img->ray->ray_angel);
	if (cos(img->ray->ray_angel) < 0 && xstep > 0)
	 	xstep *= -1;
	if (cos(img->ray->ray_angel) > 0 && xstep < 0)
	 	xstep *= -1;
	while (img->ray->hwallhity < img->s_hight && img->ray->hwallhitx < img->s_wide)
	{
		if (has_wall(img, img->ray->hwallhity ,img->ray->hwallhitx ))
			break ;
		 else if ((sin(img->ray->ray_angel) > 0))
			if (has_wall(img, img->ray->hwallhity - 1,img->ray->hwallhitx ))
				break ;
		img->ray->hwallhitx  += xstep;
		img->ray->hwallhity += ystep;
	}
}

void	vertical_inter(t_img *img)
{
	float	xstep;
	float	ystep;

	img->ray->vwallhitx = ((int)(img->x / 20) * 20);
	if (cos(img->ray->ray_angel) >= 0)
		img->ray->vwallhitx += 20;
	img->ray->vwallhity = img->y + ((img->x - img->ray->vwallhitx) * tan(img->ray->ray_angel));
	xstep = 20;
	if (cos(img->ray->ray_angel) < 0)
		xstep *= -1;
	ystep = (20  ) * tan(img->ray->ray_angel);
	if (sin(img->ray->ray_angel) >= 0 && ystep > 0)
	 	ystep *= -1;
	if (sin(img->ray->ray_angel) < 0 && ystep < 0)
	 	ystep *= -1;
	while (img->ray->vwallhity < img->s_hight && img->ray->vwallhitx < img->s_wide)
	{
		 if (cos(img->ray->ray_angel) < 0)
			if (has_wall(img, img->ray->vwallhity  ,img->ray->vwallhitx - 1 ))
				break;
		if (has_wall(img, img->ray->vwallhity ,img->ray->vwallhitx))
			break;
		img->ray->vwallhitx += xstep;
		img->ray->vwallhity += ystep;
	}
}

void    raycast(t_img *img)
{
	int	i;

	img->ray->ray_angel = img->angel -  (img->fov / 2);
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
		draw_3d_line(img, i);
		img->ray->ray_angel += img->fov / img->s_wide;
		i++;
	}
}
