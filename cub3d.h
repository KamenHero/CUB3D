/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:48:57 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/16 14:33:39 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"


typedef struct s_player
{
	int	x;
	int	y;
}		t_player;



typedef struct s_component
{
	t_player	*player;
	size_t		leny;
}			t_component;

typedef struct s_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	t_component	*comp;
}				t_data;

void	ft_cuberror(char *str);
t_data	*initialdata(void);
char	**mapping(char *arg);
char    **ft_splitting(char *str, int i, char c);
int		ft_strcmp(char *line, const char *str, int y);

#endif