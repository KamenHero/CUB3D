/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:22:36 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/31 12:15:59 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rgbs(char **splitted, t_rgb *data)
{
	int	i;
	int	j;

	i = 0;
	while (splitted[i])
	{
		j = 0;
		checkspaces(splitted[i]);
		while (splitted[i][j])
		{
			while (splitted[i][j] == ' ' || splitted[i][j] == '\n')
				j++;
			if (!ft_isdigit(splitted[i][j]) && splitted[i][j] == ' '
				&& splitted[i][j] == '\n')
				(ft_putendl_fd("error: map invalid", 2), exit(1));
			if (!splitted[i][j])
				break ;
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
	checkcolorsdigits(data->f1.r);
	checkcolorsdigits(data->f1.g);
	checkcolorsdigits(data->f1.b);
	checkcolorsdigits(data->c1.r);
	checkcolorsdigits(data->c1.g);
	checkcolorsdigits(data->c1.b);
}
