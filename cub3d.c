/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:58 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/15 17:09:50 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_skipping(char *file, int i)
{
	while (file[i] == ' '|| file[i] == '\t')
	{
		i++;
	}
	return(i);
}

void	ft_checkingpath(char *file, const char *str, int i)
{
	if (ft_strcmp())
}

void	initialpars(t_data data, char **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i][j])
	{
		j = 0;
		j = ft_skipping(file[i], j);
		if (file[i][j] == '\n')
			continue ;
		
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int	i;
	char	**file;

	i = 0;
	(void)argc;
	(void)data;
	if (argc != 2)
		(ft_putendl_fd("error", 2), exit(1));
	ft_cuberror(argv[1]);
	data = initialdata();
	file = mapping(argv[1]);
	while (file[i])
	{
		printf("%s", file[i]);
		i++;
	}

}
