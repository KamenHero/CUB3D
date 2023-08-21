/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:46:32 by onaciri           #+#    #+#             */
/*   Updated: 2023/08/21 16:45:03 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_box(t_img *img, int x, int y, char c)
{
	int	i;
	int	j;
	int	cj;
	int	ci;
	
	i = x * 64;
	j = y * 64;
	ci = 0;
	while (ci < 64)
	{	
		cj = 0;
		while (cj < 64)
		{
			if (c == '1')
				pixel_put(img, cj + j, i + ci, 0x640000);
			else if (c == '0')
				pixel_put(img, j + cj , ci + i,  0x6400ff);
			cj++;
		}
		ci++;
	}
}

void creat_map(t_img *img, t_data *data)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	int	v = 3;
	(void)data;
	while (i < 12)
	{
		j = -1;
		while (++j < 20)
		{
			if (j == 0 ||  j == 19 || i == 0 || i == 11)
				draw_box(img, i, j, '1');
			else if (!((j + v) % 2 ) && !((i + v) % 2 ) )
				draw_box(img, i, j, '1');
			else 
				draw_box(img, i, j, '0');
		}
		i++;
	}
}

void	ft(t_img	*img)
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

void	screen_st(t_data *data)
{
	t_img	img;
	img.s_hight = 1280;
	img.s_wide = 800;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.s_hight, img.s_wide, "-WESTIME-");
	img.img = mlx_new_image(img.mlx, img.s_hight, img.s_wide);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	img.angel =  0 * (M_PI / 180);
	img.x = 64 * 8;
	img.y = 6 * 64;
	img.data = data;
	creat_map(&img, data);
	draw_player(&img, img.angel);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_move, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	ft(&img);
	//mlx_loop_hook(img.mlx, , &img);
	mlx_loop(img.mlx);
}