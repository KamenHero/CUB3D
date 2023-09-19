/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:58:00 by oryadi            #+#    #+#             */
/*   Updated: 2023/09/19 15:28:45 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	initialutilhelp(t_data *data, char **file, t_ijx *ijx)
{
	if (file[ijx->i][ijx->j] == 'N')
	{
		data->no = ft_checkingpath(file[ijx->i], "NO", ijx->j);
		ijx->i++;
		ijx->x++;
		return (1);
	}
	return (0);
}

void	msgerror(void)
{
	ft_putendl_fd("Error: need a compass", 2);
	exit (1);
}

void	ft_xpm(char *str)
{
	char	*ptr;
	int		x;
	int		y;

	ptr = ".xpm";
	x = ft_strlenn(str);
	y = ft_strlenn(ptr);
	while (y >= 0)
	{
		if (str[x] != ptr[y])
		{
			ft_putendl_fd("Error : xpm emergency", 2);
			exit(-1);
		}
		x--;
		y--;
	}
}

void	check_access(char *ptr)
{
	ft_xpm(ptr);
	if (access(ptr, F_OK))
	{
		ft_putendl_fd("Error: xpm not found", 2);
		exit (1);
	}
	if (access(ptr, R_OK))
	{
		ft_putendl_fd("Error: xpm not found", 2);
		exit (1);
	}
}
