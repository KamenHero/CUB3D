/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:16:50 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/15 17:00:12 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**mapping(char *arg)
{
	int fd;
	char	*map;
	char	*tmp;
	char	**splitedmap;
	int		i;
	int     j;

	i = 0;
	map = NULL;
	splitedmap = NULL;
	fd = open(arg, O_RDONLY);
	while(1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		free(tmp);
		i++;
	}
	close(fd);
	fd = open(arg, O_RDONLY);
	splitedmap = malloc(sizeof(char *) * (i + 1));
	j = 0;
	while(j <= i)
	{
		splitedmap[j] = get_next_line(fd);
		j++;
	}
	close(fd);
	free(map);
	return(splitedmap);
}
