/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:57:06 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/13 15:53:35 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double	distancepoints(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

int	has_wall(t_img *img, double i, double j)
{
	int x;
	//int v;
	int	y;
	//int	c;

	// c = 0;
	// v = 0;
		if ((int)i < 0 || (int)j > (img->s_wide  ) ||
		(int)j < 0 || (int)i > (img->s_hight))
		return (1);
//	printf("haloa !!!!%f %f|||| %d  %d\n", x, y, (int)x, (int)y);
	// while (v < 32)
	// {
	// 	while (c < 32)
	// 	{
			x = (int)j / 20;
			y = (int)i  / 20;
			// if (x - (int)x < 0.5 && x - (int)x > 0 )
			// 	x += 0.4;
			// if ( y - (int)y < 0.5 && y - (int)y > 0)
			// 	y += 0.4;
			
			//printf("****%s \n%zu\n\n", img->data->map[(int)y], ft_strlen(img->data->map[(int)y]));
		//	if (y > img->map_y || img->data->map[(int)y])
			//	return (1);
			if ((int)y > (int)img->map_y || x >= (int)ft_strlen(img->data->map[(int)y]))
				return (1);
			if ((int)y > (int)img->map_y ||  img->data->map[(int)y][(int)x] == '1')
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
	while (sqrt(pow(x - i, 2) + pow(y - j, 2)) <= (8 ))
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
	
	i = img->x + cos(angle) * 5 ;
	j = img->y - sin(angle) * 5;
	if (j < 0 || i > (img->s_wide  ) || i < 0 || j > (img->s_hight  ) || has_wall(img, j, i))
		return ;
	if (img->data->map[(int)(j / (20 ))][(int)(img->x/(20 ))] == '1' && img->data->map[(int)(img->y/(20 ))][(int)(i / (20))] == '1' )
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
			printf("ho\n");
	// 		cj++;
	// 	}
	// 	ci++;
	// }
}


int	ft_move(int key, t_img *img)
{
	if (key == 119)//up
		draw_player(img, img->angel);
	else if (key == 115)//down
		draw_player(img, img->angel + (M_PI));
	else if (key == 100)//left
		draw_player(img, img->angel + (M_PI / 2) );
	else if (key == 97)//right
		draw_player(img, img->angel - (M_PI / 2));
	 else if (key == 65363)//
	{
		img->angel += 0.0174533;
		if (img->angel < 0)
			img->angel += 2 * M_PI;
	}
	 else if (key ==65361)//right an
	{		img->angel -= 0.0174533;
		if (img->angel >= 2 * M_PI)
			img->angel -= 2 * M_PI;
	}
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

