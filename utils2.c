/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:13:49 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/22 15:52:26 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_skipping(char *file, int i)
{
	while (file[i] == ' ' || file[i] == '\t')
	{
		i++;
	}
	if (!file[i])
		(ft_putendl_fd("error", 2), exit(1));
	return (i);
}

int	ft_len(char *file, int i)
{
	int	len;

	len = 0;
	while (file[i])
	{
		if (file[i] == ' ' || file[i] == '\t' || file[i] == '\n')
			break ;
		i++;
		len++;
	}
	return (len);
}

int	ft_len2(char *file, int i)
{
	int	len;

	len = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			break ;
		i++;
		len++;
	}
	return (len);
}

void	ft_skipto10(char **file, t_ijx ijx)
{
	while (file[ijx.i][ijx.j] != '\n')
	{
		if (file[ijx.i][ijx.j] == ' ' || file[ijx.i][ijx.j] == '\t')
			ijx.j = ft_skipping(file[ijx.i], ijx.j);
		if (!file[ijx.i][ijx.j])
			break ;
		if (file[ijx.i][ijx.j] != 'N' && file[ijx.i][ijx.j] != 'S'
			&& file[ijx.i][ijx.j] != 'E' && file[ijx.i][ijx.j] != 'W'
			&& file[ijx.i][ijx.j] != '0' && file[ijx.i][ijx.j] != '1')
			(ft_putendl_fd("error: map invalid", 2), exit(1));
		ijx.j++;
	}
}

int	ft_checklen(char **file, int *i)
{
	int	len;

	len = 0;
	while (file[*i])
	{
		len++;
		(*i)++;
	}
	return (len);
}
