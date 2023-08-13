/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:48:57 by oryadi            #+#    #+#             */
/*   Updated: 2023/08/13 15:37:01 by oryadi           ###   ########.fr       */
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
	char		*fc;
	char		**map;
	t_component	*comp;
}				t_data;



#endif