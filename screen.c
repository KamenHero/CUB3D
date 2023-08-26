/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:46:32 by onaciri           #+#    #+#             */
/*   Updated: 2023/08/22 16:15:02 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// void	player_pos(t_img *img)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (img->data->map[++i])
// 	{
// 		j = -1;
// 		while (img->data->map[i][++j])
// 		{
// 			if (img->data->map[i][j] == 'S' || img->data->map[i][j] == 'N' || img->data->map[i][j] == 'E' || img->data->map[i][j] == 'W')
// 			{
// 				img->x = (i - 2) * 64;
// 				img->y = j * 64;
// 				if (img->data->map[i][j] == 'S')
// 					img->angel = 270 * (M_PI / 180);
// 				else if (img->data->map[i][j] == 'N')
// 					img->angel = 90 * (M_PI / 180);
// 				else if (img->data->map[i][j] == 'W')
// 					img->angel = 180 * (M_PI / 180);
// 				else
// 					img->angel = 0;
// 				return ;
// 			}
// 		}
// 	}
// }

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
			{
				if (x != 0 && y != 0 && x !=1 && y != 19 && x != 11)
					printf("%d %d \n\n", x, y);
				pixel_put(img,cj + j, ci + i, 0x640000);
			}
			else if (c == '0')
				pixel_put(img, cj + j, i + ci,  0x6400ff);
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
	(void)data;
	while (img->map[i])
	{
		j = -1;
		while (img->map[i][++j])
		{
			if (img->map[i][j] == '1')
				draw_box(img, i, j, '1');
			else
				draw_box(img, i, j, '0');
		}
		i++;
	}
}

void	screen_st(t_data *data)
{
	t_img	img;
	img.s_hight = 1280;
	img.s_wide = 768;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.s_hight, img.s_wide, "-WESTIME-");
	img.img = mlx_new_image(img.mlx, img.s_hight, img.s_wide);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	img.data = data;
	img.angel = 90 * (M_PI / 180);
	img.x = 64 * 1;
	img.y = 6 * 64;//int i = 0;
	// while (img.data->map[i])
	// {
	// 	printf("%s\n", img.data->map[i]);
	// 	i++;
	// }
	//player_pos(&img);
	img.map = malloc(sizeof(char *) * 13);
	int i = 0;
	while (i < 12)
	{
		img.map[i] = malloc(21);
		i++;
	}
	img.map[i] = NULL;
	i = 0;
	int j;
	while (i < 12)
	{
		j = -1;
		while (++j < 20)
		{
			if (j == 0 ||  j == 19 || i == 0 || i == 11)
				img.map[i][j] = '1';
			else if (/*!((j + 4) % 2 ) && !((i + 3) % 2 )*/ j == 5 && i == 4 )
				img.map[i][j] = '1';
			else 
				img.map[i][j] = '0';
		}
		img.map[i][j] =  '\0';
		i++;
	}
	i = -1;
	while (++i < 12)
		printf("%s\n", img.map[i]);
	img.fov = 60 * (M_PI / 180);
	img.num_ray = img.s_wide / 1;//Check wall tick
	creat_map(&img, data);
	draw_player(&img, img.angel);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_move, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	draw_line(&img);
	//mlx_loop_hook(img.mlx, , &img);
	mlx_loop(img.mlx);
}