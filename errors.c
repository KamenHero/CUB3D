/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:23:53 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/31 12:18:44 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkerrors(t_data *data)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(data->f, ',');
	while (splitted[i])
		i++;
	if (i != 3)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	rgbs(splitted, &data->f1);
	freedouble(splitted);
	i = 0;
	splitted = ft_split(data->c, ',');
	while (splitted[i])
		i++;
	if (i != 3)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	rgbs(splitted, &data->c1);
	freedouble(splitted);
	checkcolors(data);
}

void	ft_checkplayer(char **map, size_t i, size_t *x)
{
	size_t	j;

	j = 0;
	while (map[i][j])
	{
		if (ft_strchr("NSWE", map[i][j]))
			(*x)++;
		if (ft_strchr("NSEW0", map[i][j]))
		{
			if (!map[i - 1][j] || !ft_strchr("NSEW01", map[i - 1][j]))
				(ft_putendl_fd("error: map invalid", 2), exit(1));
			if (!map[i + 1][j] || !ft_strchr("NSEW01", map[i + 1][j]))
				(ft_putendl_fd("error: map invalid", 2), exit(1));
			if (!ft_strchr("NSEW01", map[i][j + 1]))
				(ft_putendl_fd("error: map invalid", 2), exit(1));
			if (!ft_strchr("NSEW01", map[i][j - 1]))
				(ft_putendl_fd("error: map invalid", 2), exit(1));
		}
		j++;
	}
}

void	checkfirstwall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ' && map[i] != '\t')
			(ft_putendl_fd("error: map invalid2", 2), exit(1));
		i++;
	}
}

void	checkother(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!strchr("10NSWE", map[i][j]) && map[i][j] != ' '
				&& map[i][j] != '\t')
				(ft_putendl_fd("error: map invalid2", 2), exit(1));
			j++;
		}
		i++;
	}
}

void	checkwalls(char **map)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		if (map[i][0] == '0')
			(ft_putendl_fd("error: map invalid", 2), exit(1));
		if (i == 0)
			checkfirstwall(map[i]);
		else if (!map[i + 1])
			checkfirstwall(map[i]);
		else
		{
			ft_checkplayer(map, i, &x);
		}
		if (map[i][ft_strlenn(map[i])] == '0')
			(ft_putendl_fd("error: 0 felekher", 2), exit(1));
		i++;
	}
	if (x != 1)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	checkother(map);
}
