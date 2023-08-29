/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:32:34 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/27 15:57:43 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	initialutil(t_data *data, char **file, t_ijx *ijx)
{
	if (initialutilhelp(data, file, ijx))
		return (1);
	if (file[ijx->i][ijx->j] == 'S')
	{
		data->so = ft_checkingpath(file[ijx->i], "SO", ijx->j);
		ijx->i++;
		ijx->x++;
		return (1);
	}
	if (file[ijx->i][ijx->j] == 'W')
	{
		data->we = ft_checkingpath(file[ijx->i], "WE", ijx->j);
		ijx->i++;
		ijx->x++;
		return (1);
	}
	if (file[ijx->i][ijx->j] == 'E')
	{
		data->ea = ft_checkingpath(file[ijx->i], "EA", ijx->j);
		ijx->i++;
		ijx->x++;
		return (1);
	}
	return (0);
}

int	initialutil2(t_data *data, char **file, t_ijx *ijx)
{
	if (file[ijx->i][ijx->j] == 'F')
	{
		data->f = ft_checkingpath2(file[ijx->i], "F", ijx->j);
		ijx->i++;
		ijx->x++;
		return (1);
	}
	if (file[ijx->i][ijx->j] == 'C')
	{
		data->c = ft_checkingpath2(file[ijx->i], "C", ijx->j);
		ijx->i++;
		ijx->x++;
		return (1);
	}
	return (0);
}

int	initialloophelp(char **file, t_ijx *ijx, int *len)
{
	if (file[ijx->i][ijx->j] && ijx->x < 6)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	if (ijx->x == 6)
	{
		ft_skipto10(file, *ijx);
		*len = ft_checklen(file, &ijx->i);
		return (1);
	}
	return (0);
}

int	initialloop(t_data *data, char **file, t_ijx *ijx, int len)
{
	while (file[ijx->i])
	{
		len = 0;
		ijx->j = 0;
		ijx->j = ft_skipping(file[ijx->i], ijx->j);
		if (file[ijx->i][ijx->j] == '\n')
		{
			ijx->i++;
			continue ;
		}
		if (ijx->x < 6)
		{
			if (strchr("NSWE", file[ijx->i][ijx->j]))
				len = initialutil(data, file, ijx);
			else if (strchr("FC", file[ijx->i][ijx->j]))
				len = initialutil2(data, file, ijx);
			if (len)
				continue ;
		}
		if (initialloophelp(file, ijx, &len))
			break ;
		ijx->i++;
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
	len = initialloop(data, file, &ijx, len);
	if (len == 0)
		(ft_putendl_fd("error: map invalid", 2), exit(1));
	start = ijx.i - len;
	data->map = map(file, start, len);
}
