/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:47:53 by mburl             #+#    #+#             */
/*   Updated: 2019/10/16 07:55:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_map
{
	int				size;
	char			**array;
}				t_map;

typedef	struct	s_coords
{
	int		x;
	int		y;
}				t_coords;

typedef struct	s_tetros
{
	char	**pos;
	int		width;
	int		height;
	char	val;
}				t_tetros;

t_list			*free_list(t_list *lst);
void			free_tetris(t_tetros *tet);
t_tetros		*tetris_new(char **pos, int wi, int hi, char val);
t_coords		*new_point(int x, int y);
int				solve_map(t_map *map, t_list *lst);
t_map			*solve(t_list *lst);
int				f_sqrt(int n);
void			min_max(char *str, t_coords *min, t_coords *max);
t_tetros		*get_piece(char *str, char val);
t_list			*read_tetros(int fd);
void			free_map(t_map *map);
void			print_map(t_map *map);
t_map			*map_new(int size);
int				place(t_tetros *tetros, t_map *map, int x, int y);
void			set_piece(t_tetros *tetros, t_map *map,
t_coords *point, char c);

#endif
