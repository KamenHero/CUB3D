/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:46:32 by onaciri           #+#    #+#             */
/*   Updated: 2023/09/17 09:30:34 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pos(t_img *img, int i, int j)
{
	while (img->data->map[++i])
	{
		j = -1;
		while (img->data->map[i][++j])
		{
			if (img->data->map[i][j] == 'S' || img->data->map[i][j] == 'N'
				|| img->data->map[i][j] == 'E' || img->data->map[i][j] == 'W')
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

int	ft_close(t_img *img)
{
	free(img->ray);
	free_data(img->data);
	exit(0);
	return (0);
}

void	ft_init_texture(t_img *img, t_data *data)
{
	int	ls;
	int	ss;

	ls = 100;
	ss = 100;
	img->xpm_so.file = mlx_xpm_file_to_image(img->mlx, data->so, &ls, &ss);
	img->xpm_no.file = mlx_xpm_file_to_image(img->mlx, data->no, &ls, &ss);
	img->xpm_we.file = mlx_xpm_file_to_image(img->mlx, data->we, &ls, &ss);
	img->xpm_ea.file = mlx_xpm_file_to_image(img->mlx, data->ea, &ls, &ss);
	if (!img->xpm_ea.file || !img->xpm_we.file
		|| !img->xpm_no.file || !img->xpm_so.file)
		(free(img->ray), free_data(data), printf("xpm error\n"), exit(1));
	img->xpm_so.dir = mlx_get_data_addr(img->xpm_so.file,
			&img->xpm_so.bits_per_pixel,
			&img->xpm_so.size_line, &img->xpm_so.endian);
	img->xpm_no.dir = mlx_get_data_addr(img->xpm_no.file,
			&img->xpm_no.bits_per_pixel,
			&img->xpm_no.size_line, &img->xpm_no.endian);
	img->xpm_ea.dir = mlx_get_data_addr(img->xpm_ea.file,
			&img->xpm_ea.bits_per_pixel,
			&img->xpm_ea.size_line, &img->xpm_ea.endian);
	img->xpm_we.dir = mlx_get_data_addr(img->xpm_we.file,
			&img->xpm_we.bits_per_pixel,
			&img->xpm_we.size_line, &img->xpm_we.endian);
}

void	screen_st(t_data *data)
{
	t_img	img;
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	img.ray = ray;
	img.s_hight = 720;
	img.s_wide = 1280 ;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.s_wide, img.s_hight, "-WESTIME-");
	img.img = mlx_new_image(img.mlx, img.s_wide, img.s_hight);
	if (!img.img || !img.mlx)
		(free(img.ray), free_data(data), printf("xpm error\n"), exit(1));
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.data = data;
	player_pos(&img, -1, -1);
	img.fov = 60 * (M_PI / 180);
	mlx_hook(img.mlx_win, 2, 1L << 0, ft_move, &img);
	mlx_hook(img.mlx_win, 17, 0, ft_close, &img);
	ft_init_texture(&img, data);
	mlx_loop_hook(img.mlx, sceen, &img);
	mlx_loop(img.mlx);
}
