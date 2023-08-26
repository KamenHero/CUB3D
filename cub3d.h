/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:48:57 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/22 16:11:16 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <math.h>
#include <mlx.h>

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_ijx
{
	int	i;
	int	j;
	int	x;
}		t_ijx;

typedef struct s_component
{
	t_player	*player;
	size_t		leny;
}			t_component;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	t_rgb		*f1;
	t_rgb		*c1;
	char		**map;
	t_component	*comp;
}				t_data;

typedef struct	img {
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		s_hight;
	int		s_wide;
	double		fov;
	int			num_ray;
	double		x;
	double		y;
	float		dx;
	float		dy;
	double		angel;
	t_data		*data;
}	t_img;

void	ft_cuberror(char *str);
t_data	*initialdata(void);
char	**mapping(char *arg);
char    **ft_splitting(char *str, int i, char c);
int		ft_strcmp(char *line, const char *str, int y);
void	freedouble(char	**str);
void	screen_st(t_data *data);
int	ft_move(int key, t_img *img);
void	pixel_put(t_img *data, int x, int y, int color);
void	draw_player(t_img *img, double angle);
void	draw_line(t_img	*img);
#endif