/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:48:57 by oryadi            #+#    #+#             */
/*   Updated: 2023/09/15 08:43:55 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <math.h>
#include <mlx.h>

typedef struct s_ijx
{
	int	i;
	int	j;
	int	x;
}		t_ijx;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_fc
{
	int			f;
	int			c;
}				t_fc;

typedef struct s_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	t_rgb		f1;
	t_rgb		c1;
	t_fc		fc;
	char		**map;
}				t_data;

typedef struct s_ray
{
	double	ray_angel;
	double	vwallhitx;
	double	vwallhity;
	double	hwallhitx;
	double	hwallhity;
	double	x;
	double	y;
	double	dis;
}	t_ray;

typedef struct t_xpm
{
	void	*file;
	char	*dir;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_xpm;

typedef struct	s_img {
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
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		angel;
	double		dis_plane;
	double		x3d;
	double		y3d;
	double		endx;
	double		endy;
	double		deltax;
	double		deltay;
	double		pixel3d;
	int			map_y;
	int			hitwas;
	t_xpm		texUse;
	t_xpm		xpm_so;
	t_xpm		xpm_no;
	t_xpm		xpm_we;
	t_xpm		xpm_ea;
	t_data		*data;
	t_ray		*ray;
}	t_img;

void	ft_cuberror(char *str);
void	initialdata(t_data *data);
char	**mapping(char *arg);
char	**ft_splitting(char *str, int i, char c);
int		ft_strcmp(char *line, const char *str, int y);
void	freedouble(char	**str);
int		ft_skipping(char *file, int i);
int		ft_len(char *file, int i);
int		ft_len2(char *file, int i);
char	*ft_checkingpath(char *file, const char *str, int i);
char	*ft_checkingpath2(char *file, const char *str, int i);
void	ft_skipto10(char **file, t_ijx ijx);
int		ft_checklen(char **file, int *i);
char	**map(char **file, int start, int len);
char	*ft_map2d(char *file, char *map, int j);
void	checkspaces(char *str);
void	rgbs(char **splitted, t_rgb *data);
void	checkcolorsdigits(int i);
void	checkcolors(t_data *data);
void	checkerrors(t_data *data);
void	ft_checkplayer(char **map, size_t i, size_t *x);
void	checkwalls(char **map);
void	initialpars(t_data *data, char **file);
int		initialutilhelp(t_data *data, char **file, t_ijx *ijx);
void	screen_st(t_data *data);
int		ft_move(int key, t_img *img);
void	pixel_put(t_img *data, int x, int y, int color);
void	draw_player(t_img *img, double angle);
void	draw_line(t_img	*img, int color);
void    raycast(t_img *img);
int		has_wall(t_img *img, double i, double j);
void    rem_raycast(t_img *img);
void	creat_map(t_img *img);
void	draw_box(t_img *img, int x, int y, char c);
double	distancepoints(double x1, double y1, double x2, double y2);
void    draw_3d_line(t_img *img, int i);
void	free_data(t_data *data);

#endif