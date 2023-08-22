/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:58 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/22 16:50:44 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**file;
	int		i;

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
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}
