/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:57:06 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/16 18:19:53 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distancepoints(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

int	has_wall(t_img *img, double i, double j)
{
	int	x;
	int	y;

	if ((int)i < 0 || (int)j > img->s_wide
		|| (int)j < 0 || (int)i > img->s_hight)
		return (1);
	x = (int)j / 20;
	y = (int)i / 20;
	if ((int)y > (int)img->map_y
		|| x >= (int)ft_strlen(img->data->map[(int)y]))
		return (1);
	if ((int)y > (int)img->map_y || img->data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

void	draw_player(t_img *img, double angle)
{
	double	i;
	double	j;

	i = img->x + cos(angle) * 10;
	j = img->y - sin(angle) * 10;
	if (j < 0 || i > img->s_wide || i < 0 || j > img->s_hight
		|| has_wall(img, j, i))
		return ;
	if (img->data->map[(int)(j / 20)][(int)(img->x / 20)] == '1'
		&& img->data->map[(int)(img->y / 20)][(int)(i / 20)] == '1')
		return ;
	img->x = i;
	img->y = j;
}

int	ft_move(int key, t_img *img)
{
	if (key == 119)
		draw_player(img, img->angel);
	else if (key == 115)
		draw_player(img, img->angel + (M_PI));
	else if (key == 100)
		draw_player(img, img->angel + (M_PI / 2));
	else if (key == 97)
		draw_player(img, img->angel - (M_PI / 2));
	else if (key == 65363)
	{
		img->angel += 0.0174533;
		if (img->angel < 0)
			img->angel += 2 * M_PI;
	}
	else if (key == 65361)
	{
		img->angel -= 0.0174533;
		if (img->angel >= 2 * M_PI)
			img->angel -= 2 * M_PI;
	}
	raycast(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
