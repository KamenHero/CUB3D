/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:16:50 by oryadi            #+#    #+#             */
/*   Updated: 2023/09/16 17:57:24 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minor_error(int i)
{
	if (i == -1)
		exit (1);
}

char	**mapping(char *arg)
{
	t_ijx	ijf;
	char	*tmp;
	char	**splitedmap;

	ijf.i = 0;
	splitedmap = NULL;
	ijf.x = open(arg, O_RDONLY);
	minor_error(ijf.i);
	while (1)
	{
		tmp = get_next_line(ijf.x);
		if (tmp == NULL)
			break ;
		free(tmp);
		ijf.i++;
	}
	close(ijf.x);
	ijf.x = open(arg, O_RDONLY);
	minor_error(ijf.i);
	splitedmap = malloc(sizeof(char *) * (ijf.i + 1));
	ijf.j = 0;
	while (ijf.j <= ijf.i)
		splitedmap[ijf.j++] = get_next_line(ijf.x);
	close(ijf.x);
	return (splitedmap);
}
