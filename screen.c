/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:46:32 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/14 19:59:04 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	player_pos(t_img *img, int i)
{
	int	j;

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
	img->map_y = i;
}

int	sceen(t_img *img)
{
	raycast(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if  (x < 0 || y < 0 || x >= 1280 || y >= 768)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(int keycode, t_img *img)
{
	printf("yo\n");
	free(img->ray);
	free_data(img->data);
	printf("yo\n");
	//mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
	return (0);
}

void	screen_st(t_data *data)
{
	t_img	img;
	t_ray	*ray;
	int	ls = 64;
	int ss = 64;

	ray = malloc(sizeof(t_ray));
	img.ray = ray;
	img.s_hight = 768;
	img.s_wide =1280 ;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx,img.s_wide,  img.s_hight, "-WESTIME-");
	img.img = mlx_new_image(img.mlx,img.s_wide ,img.s_hight );
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	img.data = data;
	player_pos(&img, -1);
	img.fov = 60 * (M_PI / 180);
	draw_player(&img, img.angel);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_move, &img);
	//mlx_hook(img.mlx_win, 17, 1L<<17, ft_close, &img);
	img.xpm_so.file = mlx_xpm_file_to_image(img.mlx, data->so, &ls, &ss);
	img.xpm_no.file = mlx_xpm_file_to_image(img.mlx, data->no, &ls, &ss);
	img.xpm_we.file = mlx_xpm_file_to_image(img.mlx, data->we, &ls, &ss);
	img.xpm_ea.file = mlx_xpm_file_to_image(img.mlx, data->ea, &ls, &ss);
	img.xpm_so.dir = mlx_get_data_addr(img.xpm_so.file, &img.xpm_so.bits_per_pixel, &img.xpm_so.size_line, &img.xpm_so.endian);
	img.xpm_no.dir = mlx_get_data_addr(img.xpm_no.file, &img.xpm_no.bits_per_pixel, &img.xpm_no.size_line, &img.xpm_no.endian);
	img.xpm_ea.dir = mlx_get_data_addr(img.xpm_ea.file, &img.xpm_ea.bits_per_pixel, &img.xpm_ea.size_line, &img.xpm_ea.endian);
	img.xpm_we.dir = mlx_get_data_addr(img.xpm_we.file, &img.xpm_we.bits_per_pixel, &img.xpm_we.size_line, &img.xpm_we.endian);
	mlx_loop_hook(img.mlx, sceen, &img);
	mlx_loop(img.mlx);
}