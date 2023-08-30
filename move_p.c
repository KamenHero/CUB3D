/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:57:06 by onaciri           #+#    #+#             */
/*   Updated: 2023/08/30 09:59:20 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


float	distancepoints(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

int	has_wall(t_img *img, double i, double j)
{
	double x;
	//int v;
	double	y;
	//int	c;

	// c = 0;
	// v = 0;
		if ((int)i < 0 || (int)j > (img->s_wide * 0.2) ||
		(int)j < 0 || (int)i > (img->s_hight*  0.2))
		return (1);
//	printf("haloa !!!!%f %f|||| %d  %d\n", x, y, (int)x, (int)y);
	// while (v < 32)
	// {
	// 	while (c < 32)
	// 	{
			x = (int)(j / (64 *0.2));
			y = (int)(i  / (64 * 0.2));
			// if (x - (int)x < 0.5 && x - (int)x > 0 )
			// 	x += 0.4;
			// if ( y - (int)y < 0.5 && y - (int)y > 0)
			// 	y += 0.4;
			printf("****%s \n%zu\n\n", img->map[(int)y], ft_strlen(img->map[(int)y]));
			if (x >= ft_strlen(img->map[(int)y]))
				return (1);
			if (img->map[(int)y][(int)x] == '1')
			{
				// printf("has wall%f %f||| %d %d\n", x, y, (int)x, (int)y);
				return (1);
			}
	// 		c++;
	// 	}
	// 	v++;
	// }
	return (0);
}

void	del_line(t_img	*img)
{
	float	x;
	float	y;
	int		i;
	int		j;


	x = img->x;
	y = img->y;
	i = (int )x;
	j = (int )y;
	while (sqrt(pow(x - i, 2) + pow(y - j, 2)) <= 16)
	{
		pixel_put(img, x, y, 0x00ff00);
		x += cos(img->angel);
		y -= sin(img->angel);
	}
}
void	draw_line(t_img	*img, int color)
{
	float	x;
	float	y;
	int		i;
	int		j;


	x = img->x;
	y = img->y;
	if (x < 0 || x > img->s_wide ||
		x < 0 || y  > img->s_hight)
		return ;
	i = (int )x;
	j = (int )y;
	while (sqrt(pow(x - i, 2) + pow(y - j, 2)) <= (16 *0.2))
	{
		pixel_put(img, x, y, color);
		x += cos(img->angel);
		y -= sin(img->angel);
	}
}

// void	delet_ply(t_img *img)
// {
// 	float 	ci;
//     float 	cj;

// 	ci = 0;
// 	while (ci < 32)
// 	{
// 		cj = 0;
// 		while (cj < 32)
// 		{
// 			if (ci < 32 && cj < 32)
// 				pixel_put(img, img->x ,img->ray->ray_angel
// 	}
// }
void	draw_player(t_img *img, double angle)
{
    // double 		ci;
    // double 		cj;
	double		i;
	double		j;
	
	i = img->x + cos(angle) * 10 ;
	j = img->y - sin(angle) * 10;
	if (j < 0 || i > (img->s_wide * 0.2) || i < 0 || j > (img->s_hight * 0.2) || has_wall(img, j, i))
		return ;
	//delet_ply(img);
	img->x = i;
	img->y = j;
	// ci = 0;
	// while (ci < 32)
	// {
	// 	cj = 0;
	// 	while (cj < 32)
	// 	{
			pixel_put(img,  img->x , img->y,  0x00ff00);
	// 		cj++;
	// 	}
	// 	ci++;
	// }
}


int	ft_move(int key, t_img *img)
{
	// printf("%d\n", key);
	//del_line(img);
	//rem_raycast(img);
	creat_map(img);
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
		img->angel += 0.0174533;
		if (img->angel < 0)
			img->angel += 2 * M_PI;
	
	}
	 else if (key == 65363)//right an
	{		img->angel -= 0.0174533;
		if (img->angel >= 2 * M_PI)
			img->angel -= 2 * M_PI;
	}

	draw_line(img, 0xFFFFFF);
	raycast(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

