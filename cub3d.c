/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:58 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/16 18:04:38 by oryadi           ###   ########.fr       */
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

void	initialpars(t_data *data, char **file)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (file[i])
	{
		j = 0;
		j = ft_skipping(file[i], j);
		if (file[i][j] == '\n')
		{
			i++;
			continue ;
		}
		if (x == 0)
		{
			data->no = ft_checkingpath(file[i], "NO", j);
			i++;
			x++;
			continue;
		}
		if (x == 1)
		{
			data->so = ft_checkingpath(file[i], "SO", j);
			i++;
			x++;
			continue;
		}
		if (x == 2)
		{
			data->we = ft_checkingpath(file[i], "WE", j);
			i++;
			x++;
			continue;
		}
		if (x == 3)
		{
			data->ea = ft_checkingpath(file[i], "EA", j);
			i++;
			x++;
			continue;
		}
		if (x == 4)
		{
			data->f = ft_checkingpath(file[i], "F", j);
			i++;
			x++;
			continue;
		}
		if (x == 5)
		{
			data->c = ft_checkingpath(file[i], "C", j);
			i++;
			x++;
			continue;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**file;
	// int	i;

	// i = 0;
	(void)argc;
	(void)data;
	if (argc != 2)
		(ft_putendl_fd("error", 2), exit(1));
	ft_cuberror(argv[1]);
	data = initialdata();
	file = mapping(argv[1]);
	initialpars(data, file);
	// while (file[i])
	// {
	// 	printf("%s", file[i]);
	// 	i++;
	// }
	printf("%s\n", data->no);
	printf("%s\n", data->so);
	printf("%s\n", data->we);
	printf("%s\n", data->ea);
	printf("%s\n", data->f);
	printf("%s\n", data->c);
}
