/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:40:42 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/16 19:08:41 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	texture(t_img *img, int i, int y_tex)
{
	int		xoff;
	float	fin;

	if (img->hitwas == 1)
		xoff = (int)((img->ray->y / 20) * 100) % 100;
	else
		xoff = (int)((img->ray->x / 20) * 100) % 100;
	fin = (y_tex * img->texuse.size_line)
		+ (xoff * (img->texuse.bits_per_pixel / 8));
	pixel_put(img, i, (int)img->y3d,
		*((unsigned int *)(img->texuse.dir + (int)fin)));
}

void	chose_texture(t_img *img)
{
	if (img->ray->look == 2)
	{
		img->texuse = img->xpm_no;
		img->texuse.dir = img->xpm_no.dir;
	}
	else if (img->ray->look == 1)
	{
		img->texuse = img->xpm_we;
		img->texuse.dir = img->xpm_we.dir;
	}
	else if (img->ray->look == 3)
	{
		img->texuse = img->xpm_so;
		img->texuse.dir = img->xpm_so.dir;
	}
	else
	{
		img->texuse = img->xpm_ea;
		img->texuse.dir = img->xpm_ea.dir;
	}
}

void	ft_fc(t_img *img, int i)
{
	int		j;

	j = -1;
	while (++j <= img->y3d)
		pixel_put(img, i, j, img->data->fc.c);
	j = img->endy;
	while (j < img->s_hight)
	{
		pixel_put(img, i, j, img->data->fc.f);
		j++;
	}
}

void	ft_init(t_img *img)
{
	img->dis_plane = (img->s_wide / 2);
	img->ray->dis = cos(img->angel - img->ray->ray_angel) * img->ray->dis;
	img->line_height = ((20 / img->ray->dis)) * img->dis_plane;
	img->y3d = (int)(img->s_hight / 2) - (img->line_height / 2);
	img->endy = (int)(img->s_hight / 2) + (img->line_height / 2);
}

void	draw_3d_line(t_img *img, int i)
{
	float	ygrid;
	float	y_tex;

	ft_init(img);
	if (img->y3d < 0)
		img->y3d = 0;
	if (img->endy > img->s_hight)
		img->endy = img->s_hight;
	ft_fc(img, i);
	ygrid = 64 / img->line_height;
	y_tex = 0;
	if (img->line_height > img->s_hight)
		y_tex = ygrid * (img->line_height - img->s_hight) / 2;
	while (img->y3d < img->endy)
	{
		chose_texture(img);
		texture(img, i, y_tex);
		y_tex += ygrid;
		img->y3d++;
	}
}
