/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:57:06 by onaciri           #+#    #+#             */
/*   Updated: 2023/08/22 15:56:22 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_wall(t_img *img, int i, int j)
{
	int x;
	int v;
	int	y;
	int	c;

	c = 0;
	v = 0;
	x = (i  + c) / 64;
	y = (j+ v) / 64;
	printf("haloa !!!!%d %d\n", (int)x, (int)y);
	while (v < 32)
	{
		while (c < 32)
		{
			x = (i  + c) / 64;
			y = (j + v) / 64;
			if (img->map[(int)x][(int)y] == '1')
			{
				printf("%d %d \n", (int)x, (int)y);
				return (1);
			}
			c++;
		}
		v++;
	}
	return (0);
}

void	del_line(t_img	*img)
{
	float	x;
	float	y;
	int		i;
	int		j;


	x = img->x + 16;
	y = img->y + 16;
	i = (int )x;
	j = (int )y;
	while (sqrt(pow(x - i, 2) + pow(y - j, 2)) <= 15)
	{
		pixel_put(img, x, y, 0x00ff00);
		x += cos(img->angel);
		y -= sin(img->angel);
	}
}
void	draw_line(t_img	*img)
{
	float	x;
	float	y;
	int		i;
	int		j;


	x = img->x + 16;
	y = img->y + 16;
	i = (int )x;
	j = (int )y;
	while (sqrt(pow(x - i, 2) + pow(y - j, 2)) <= 15)
	{
		pixel_put(img, x, y, 0xFFFFFF);
		x += cos(img->angel);
		y -= sin(img->angel);
	}
}

void	delet_ply(t_img *img)
{
	float 	ci;
    float 	cj;

	ci = 0;
	while (ci < 32)
	{
		cj = 0;
		while (cj < 32)
		{
			if (ci < 32 && cj < 32)
				pixel_put(img, ci + img->x , img->y + cj,  0x6400ff);
			cj++;
		}
		ci++;
	}
}
void	draw_player(t_img *img, double angle)
{
    double 		ci;
    double 		cj;
	double		i;
	double		j;
	
	i = img->x + cos(angle) * 20;
	j = img->y - sin(angle) * 20;
	if (i < 0 || j + 63 > img->s_wide || j < 0 || i + 63 > img->s_hight || has_wall(img, j, i))
		return ;
	delet_ply(img);
	img->x = i;
	img->y = j;
	ci = 0;
	while (ci < 32)
	{
		cj = 0;
		while (cj < 32)
		{
			pixel_put(img, ci + img->x , img->y + cj,  0x00ff00);
			cj++;
		}
		ci++;
	}
}


int	ft_move(int key, t_img *img)
{
	printf("%d\n", key);
	del_line(img);
	if (key == 119)//up
		draw_player(img, img->angel);
	else if (key == 115)//down
		draw_player(img, img->angel + (M_PI));
	else if (key == 97)//left
		draw_player(img, img->angel + (M_PI / 2) );
	else if (key == 100)//right
		draw_player(img, img->angel - (M_PI / 2));
	 else if (key == 65361)//
	{
		img->angel -= 0.1;
		if (img->angel < 0)
			img->angel += 2 * M_PI;
	
	}
	 else if (key == 65363)//right an
	{		img->angel += 0.1;
		if (img->angel > 2 * M_PI)
			img->angel -= 2 * M_PI;
	}

	draw_line(img);
	//cast_ray();
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

