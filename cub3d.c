/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onaciri <onaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:58 by oryadi            #+#    #+#             */
/*   Updated: 2023/09/15 17:18:10 by onaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_data *data)
{
	freedouble(data->map);
	free(data->f);
	free(data->c);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free(data);
}

int	create_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**file;

	(void)argc;
	data = malloc(sizeof(t_data));
	initialdata(data);
	file = mapping(argv[1]);
	initialpars(data, file);
	freedouble(file);
	checkerrors(data);
	checkwalls(data->map);
	data->fc.f = create_hex(data->f1.r, data->f1.g, data->f1.b);
	data->fc.c = create_hex(data->c1.r, data->c1.g, data->c1.b);
	screen_st(data);
	free_data(data);
}
