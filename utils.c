/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:14:33 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/16 16:15:10 by oryadi           ###   ########.fr       */
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

t_data	*initialdata(void)
{
	t_data	*data;
	t_player	*player;

	data = malloc(sizeof(t_data));
	data->comp = malloc(sizeof(t_component));
	player = malloc(sizeof(t_player));
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->c = NULL;
	data->f = NULL;
	data->map = NULL;
	player->x = 0;
	player->y = 0;
	data->comp->leny = 0;
	data->comp->player = player;
	return(data);
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
