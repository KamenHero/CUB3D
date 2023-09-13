/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:46:32 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/13 15:54:36 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	player_pos(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (img->data->map[++i])
	{
		j = -1;
		while (img->data->map[i][++j])
		{
			if (img->data->map[i][j] == 'S' || img->data->map[i][j] == 'N' || img->data->map[i][j] == 'E' || img->data->map[i][j] == 'W')
			{
				img->x = (j * 20) + 10;
				img->y = (i * 20) + 10;
				if (img->data->map[i][j] == 'S')
					img->angel = 270 * (M_PI / 180);
				else if (img->data->map[i][j] == 'N')
					img->angel = 90 * (M_PI / 180);
				else if (img->data->map[i][j] == 'W')
					img->angel = 180 * (M_PI / 180);
				else
					img->angel = 0;
				break ;
			}
		}
	}
	printf("****i == %d %f %f**\n",i, img->x, img->y);
	img->map_y = i;
}

int	sceen(t_img *img)
{
	creat_map(img);
	pixel_put(img, img->x, img->y, 0x00ff00);
	draw_line(img, 0xFFFFFF);
	//draw_player(img, img->angel);
	raycast(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

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
	
	i = x * (20  );
	j = y * (20  );
	ci = 0;
	while (ci < (20  ))
	{	
		cj = 0;
		while (cj < (20  ))
		{
			if (c == '1')
				pixel_put(img,cj + j, ci + i, 0x640000);
			else if (c == '0')
				pixel_put(img, cj + j, i + ci,  0x6400ff);
			if (ci == (19) || cj == (19  ))
			pixel_put(img, cj + j, i + ci,  0x000000);
			cj++;
		}
		ci++;
	}
}


void creat_map(t_img *img)
{
	int i;
	int	j;
	
	i = 0;
	while (img->data->map[i])
	{
		j = -1;
		while (img->data->map[i][++j])
		{
			if (img->data->map[i][j] == '1')
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
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	img.ray = ray;
	img.s_hight = 768;
	img.s_wide =1280 ;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx,img.s_wide,  img.s_hight, "-WESTIME-");
	img.img = mlx_new_image(img.mlx,img.s_wide ,img.s_hight );
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	img.data = data;
	//img.angel = M_PI /2;
	//img.x = (64  * 7);
	//img.y = (4 * 64);//int i = 0;
	// while (img.data->map[i])
	// {
	// 	printf("%s\n", img.data->map[i]);
	// 	i++;
	// }
	printf("lol\n");
	player_pos(&img);
	printf("%f %f\n", img.x / 64, img.y /64);
	// img.map = malloc(sizeof(char *) * 13);
	// int i = 0;
	// while (i < 12)
	// {
	// 	img.map[i] = malloc(21);
	// 	i++;
	// }
	// img.map[i] = NULL;
	// i = 0;
	// int j;
	// while (i < 12)
	// {
	// 	j = -1;
	// 	while (++j < 20)
	// 	{
	// 		if (j == 0 ||  j == 19 || i == 0 || i == 11)
	// 			img.map[i][j] = '1';
	// 		else if (/*!((j + 4) % 2 ) && !((i + 3) % 2 )*/ (j == 5 && i == 4) || (i == 3 && j == 4))
	// 			img.map[i][j] = '1';
	// 		else 
	// 			img.map[i][j] = '0';
	// 	}
	// 	img.map[i][j] =  '\0';
	// 	i++;
	// }
	int i = -1;
	while (img.data->map[++i])
		printf("%s\n", img.data->map[i]);
	img.fov = 60 * (M_PI / 180);
	//img.num_ray = img.s_wide / 1;//Check wall tick
	//creat_map(&img);
	draw_player(&img, img.angel);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_move, &img);
	//mlx_hook(img.mlx_win, 3, 1L << 1, &butt_released, &img);
	//mlx_hook(img.mlx_win, 17, 1L << 17, &clicked_cross, &img);
	//mlx_loop_hook(img.mlx, &render_next_frame, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	//draw_line(&img,img.angel, 0xFFFFFF);
	mlx_loop_hook(img.mlx, sceen, &img);
	mlx_loop(img.mlx);
}