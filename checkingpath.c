/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:17:58 by oryadi            #+#    #+#             */
/*   Updated: 2023/09/16 18:08:15 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	msgerror(void)
{
	ft_putendl_fd("Error: need a compass", 2);
	exit (1);
}

void	checkafter(char *file, int i)
{
	while (file[i] != '\n')
	{
		while (file[i] == ' ' || file[i] == '\t' || file[i] == ',')
			i++;
		if (file[i] == '\n')
			break ;
		else
		{
			ft_putendl_fd("Error: need a l3ba", 2);
			exit (1);
		}
		i++;
	}
}

char	*ft_checkingpath(char *file, const char *str, int i)
{
	char	*ptr;
	int		len;
	int		y;

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
		msgerror();
	checkafter(file, i);
	check_access(ptr);
	return (ptr);
}

void	checkdig(char *file, int i)
{
	i += 1;
	while (file[i] != '\n')
	{
		while (file[i] == ' ' || file[i] == '\t' || file[i] == ',')
			i++;
		if (file[i] == '\n')
			break ;
		if (!ft_isdigit(file[i]))
		{
			ft_putendl_fd("Error: zyada", 2);
			exit (1);
		}
		i++;
	}
}

char	*ft_checkingpath2(char *file, const char *str, int i)
{
	char	*ptr;
	int		len;
	int		y;

	len = 0;
	y = 0;
	checkdig(file, i);
	if (ft_strcmp(file, str, i) == 0)
	{
		i += 1;
		i = ft_skipping(file, i);
		len = ft_len2(file, i);
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
		msgerror();
	return (ptr);
}
