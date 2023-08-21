/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:58 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/21 16:55:39 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_skipping(char *file, int i)
{
	while (file[i] == ' '|| file[i] == '\t')
	{
		i++;
	}
	if (!file[i])
		(ft_putendl_fd("error", 2), exit(1));
	return(i);
}

int	ft_len(char *file, int i)
{
	int	len;

	len = 0;
	while (file[i])
	{
		if (file[i] == ' '|| file[i] == '\t' || file[i] == '\n')
			break;
		i++;
		len++;
	}
	return(len);
}

int	ft_len2(char *file, int i)
{
	int	len;

	len = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			break;
		i++;
		len++;
	}
	return(len);
}

char*	ft_checkingpath(char *file, const char *str, int i)
{
	char	*ptr;
	int	len;
	int	y;

	len = 0;
	y = 0;
	if (ft_strcmp(file, str, i) == 0)
	{
		i += 2;
		i = ft_skipping(file, i);
		len = ft_len(file, i);
		ptr = malloc(sizeof(char) * (len + 1));
		while (y < len)
		{
			ptr[y] = file[i];
			i++;
			y++;
		}
		ptr[y] = '\0';
	}
	else
	{
		ft_putendl_fd("Error: need a compass", 2);
		exit (1);
	}
	return (ptr);
}

char*	ft_checkingpath2(char *file, const char *str, int i)
{
	char	*ptr;
	int	len;
	int	y;

	len = 0;
	y = 0;
	if (ft_strcmp(file, str, i) == 0)
	{
		i += 1;
		i = ft_skipping(file, i);
		len = ft_len2(file, i);
		ptr = malloc(sizeof(char) * (len + 1));
		while (y < len)
		{
			ptr[y] = file[i];
			i++;
			y++;
		}
		ptr[y] = '\0';
	}
	else
	{
		ft_putendl_fd("Error: need a compass", 2);
		exit (1);
	}
	return (ptr);
}

void	ft_skipto10(char **file, t_ijx ijx)
{
	while (file[ijx.i][ijx.j] != '\n')
	{
		if (file[ijx.i][ijx.j] == ' '|| file[ijx.i][ijx.j] == '\t')
			ijx.j = ft_skipping(file[ijx.i], ijx.j);
		if (!file[ijx.i][ijx.j])
			break ;
		if (file[ijx.i][ijx.j] != 'N' && file[ijx.i][ijx.j] != 'S'
			&& file[ijx.i][ijx.j] != 'E' && file[ijx.i][ijx.j] != 'W'
			&& file[ijx.i][ijx.j] != '0' && file[ijx.i][ijx.j] != '1')
			{
				(ft_putendl_fd("error: map invalid", 2), exit(1));
			}
		ijx.j++;
	}
}

char	*ft_map2d(char *file, char *map, int j)
{
	int	i;

	i = 0;
	while (i != j)
	{
		map[i] = file[i];
		i++;
	}
	map[i] = '\0';
	return (map);
}

char	**map(char **file, int start, int len)
{
	int		j;
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		j = 0;
		while (file[start][j])
		{
			if (file[start][j] == '\n')
				break ;
			j++;
		}
		map[i] = malloc(sizeof(char) * (j + 1));
		map[i] = ft_map2d(file[start], map[i], j);
		i++;
		start++;
	}
	map[i] = NULL;
	return (map);
}

int	ft_checklen(char **file, int *i)
{
	int	len;

	len = 0;
	while (file[*i])
	{
		len++;
		(*i)++;
	}
	return (len);
}

void	initialpars(t_data *data, char **file)
{
	t_ijx	ijx;
	int		len;
	int		start;

	len = 0;
	start = 0;
	ijx.i = 0;
	ijx.x = 0;
	while (file[ijx.i])
	{
		ijx.j = 0;
		ijx.j = ft_skipping(file[ijx.i], ijx.j);
		if (file[ijx.i][ijx.j] == '\n')
		{
			ijx.i++;
			continue ;
		}
		if (ijx.x == 0)
		{
			data->no = ft_checkingpath(file[ijx.i], "NO", ijx.j);
			ijx.i++;
			ijx.x++;
			continue;
		}
		if (ijx.x == 1)
		{
			data->so = ft_checkingpath(file[ijx.i], "SO", ijx.j);
			ijx.i++;
			ijx.x++;
			continue;
		}
		if (ijx.x == 2)
		{
			data->we = ft_checkingpath(file[ijx.i], "WE", ijx.j);
			ijx.i++;
			ijx.x++;
			continue;

		}
		if (ijx.x == 3)
		{
			data->ea = ft_checkingpath(file[ijx.i], "EA", ijx.j);
			ijx.i++;
			ijx.x++;
			continue;
		}
		if (ijx.x == 4)
		{
			data->f = ft_checkingpath2(file[ijx.i], "F", ijx.j);
			ijx.i++;
			ijx.x++;
			continue;
		}
		if (ijx.x == 5)
		{
			data->c = ft_checkingpath2(file[ijx.i], "C", ijx.j);
			ijx.i++;
			ijx.x++;
			continue;
		}
		if (ijx.x == 6)
		{
			ft_skipto10(file, ijx);
			len = ft_checklen(file, &ijx.i);
			break;
		}
		ijx.i++;
	}
	if (len == 0)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	start = ijx.i - len - 2;
	data->map = map(file, start, len);
}

void	checkspaces(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (x == 0  && ft_isdigit(str[i]))
			x = 1;
		if (x == 1 && (str[i] == ' ' || str[i] == '\t'))
		{
			if (str[i + 1] && ft_isdigit(str[i + 1]))
				(ft_putendl_fd("error: map invalid", 2), exit(1));
		}
		i++;
	}
}

void	rgbs(char **splitted, t_rgb *data)
{
	int	i;
	int	j;

	i = 0;
	while (splitted[i])
	{
		j = 0;
		checkspaces(splitted[i]);
		while(splitted[i][j])
		{
			while (splitted[i][j] == ' ' || splitted[i][j] == '\n')
				j++;
			if (!ft_isdigit(splitted[i][j]) && splitted[i][j] == ' '
				&& splitted[i][j] == '\n')	
				(ft_putendl_fd("error: map invalid", 2), exit(1));
			j++;
		}
		i++;
	}
	data->r = ft_atoi(splitted[0]);
	data->g = ft_atoi(splitted[1]);
	data->b = ft_atoi(splitted[2]);
}

void	checkcolorsdigits(int i)
{
	if (i < 0 || i > 255)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
}

void	checkcolors(t_data *data)
{
	checkcolorsdigits(data->f1->r);
	checkcolorsdigits(data->f1->g);
	checkcolorsdigits(data->f1->b);
	checkcolorsdigits(data->c1->r);
	checkcolorsdigits(data->c1->g);
	checkcolorsdigits(data->c1->b);
}

void	checkerrors(t_data *data)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(data->f, ',');
	while(splitted[i])
		i++;
	if (i != 3)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	rgbs(splitted, data->f1);
	freedouble(splitted);
	i = 0;
	splitted = ft_split(data->c, ',');
	while(splitted[i])
		i++;
	if (i != 3)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	rgbs(splitted, data->c1);
	freedouble(splitted);
	checkcolors(data);
}

void	ft_checkplayer(char **map, size_t i, size_t j, size_t *x)
{
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
		(*x)++;
	if (!map[i + 1][j] || !map[i - 1][j])
				(ft_putendl_fd("error: map invalid", 2), exit(1));
	if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t')
				(ft_putendl_fd("error: map invalid", 2), exit(1));
	if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t')
				(ft_putendl_fd("error: map invalid", 2), exit(1));
	if (map[i][j + 1] == ' ' || map[i][j + 1] == '\t')
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t')
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	if ((*x) != 1 )
		(ft_putendl_fd("error: map invalid", 2), exit(1));
}

void	checkwalls(char **map)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	x = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (!map[i][j])
		{
			i++;
			continue;
		}
		if (map[i][j] == '0')
			(ft_putendl_fd("error: map invalid", 2), exit(1));
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == '0')
				ft_checkplayer(map, i, j, &x);
			j++;
		}
		if (map[i][j - 1] == '0')
			(ft_putendl_fd("error: map invalid", 2), exit(1));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**file;
	int	i;

	i = 0;
	(void)argc;
	(void)data;
	if (argc != 2)
		(ft_putendl_fd("error", 2), exit(1));
	ft_cuberror(argv[1]);
	data = initialdata();
	file = mapping(argv[1]);
	initialpars(data, file);
	freedouble(file);
	checkerrors(data);
	checkwalls(data->map);
	// printf("%d\n", data->c1->r);
	// printf("%d\n", data->c1->g);
	// printf("%d\n", data->c1->b);
	// printf("%d\n", data->f1->r);
	// printf("%d\n", data->f1->g);
	// printf("%d\n", data->f1->b);
	// printf("%s\n", data->no);
	// printf("%s\n", data->we);
	// printf("%s\n", data->ea);
	// printf("%s\n", data->f);
	// printf("%s\n", data->c);
	// while (data->map[i])
	// {
	// 	printf("%s\n", data->map[i]);
	// 	i++;
	// }
	screen_st(data);
}
