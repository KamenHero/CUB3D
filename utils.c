/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:14:33 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/31 12:28:08 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cuberror(char *str)
{
	char	*ptr;
	int		x;
	int		y;

	ptr = ".cub";
	x = ft_strlenn(str);
	y = ft_strlenn(ptr);
	while (y >= 0)
	{
		if (str[x] != ptr[y])
		{
			ft_putendl_fd("Error : cub chi kwiyess", 2);
			exit(-1);
		}
		x--;
		y--;
	}
}

void	initialdata(t_data *data)
{
	data->f1.r = 0;
	data->f1.g = 0;
	data->f1.b = 0;
	data->c1.r = 0;
	data->c1.g = 0;
	data->c1.b = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->c = NULL;
	data->f = NULL;
	data->map = NULL;
}

int	ft_strcmp(char *line, const char *str, int y)
{
	int	i;

	i = 0;
	while (line[y] == str[i])
	{
		y++;
		i++;
		if (!str[i])
			return (0);
	}
	return (line[y] - str[i]);
}

void	freedouble(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	checkspaces(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (x == 0 && ft_isdigit(str[i]))
			x = 1;
		if (x == 1 && (str[i] == ' ' || str[i] == '\t'))
		{
			if (str[i + 1] && ft_isdigit(str[i + 1]))
				(ft_putendl_fd("error: map invalid", 2), exit(1));
		}
		i++;
	}
}
