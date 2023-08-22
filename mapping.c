/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:20:50 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/21 17:21:18 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
