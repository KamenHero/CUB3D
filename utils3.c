/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:58:00 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/27 15:58:35 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	initialutilhelp(t_data *data, char **file, t_ijx *ijx)
{
	if (file[ijx->i][ijx->j] == 'N')
	{
		data->no = ft_checkingpath(file[ijx->i], "NO", ijx->j);
		ijx->i++;
		ijx->x++;
		return (1);
	}
	return (0);
}
