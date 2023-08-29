/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:48:57 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/27 15:58:32 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

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
}				t_data;

void	ft_cuberror(char *str);
t_data	*initialdata(void);
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

#endif