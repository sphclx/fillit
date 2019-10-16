/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <abenton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:17:18 by mburl             #+#    #+#             */
/*   Updated: 2019/10/16 14:23:03 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	set_piece(t_tetros *tetros, t_map *map, t_coords *point, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetros->width)
	{
		j = 0;
		while (j < tetros->height)
		{
			if (tetros->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int		place(t_tetros *tetros, t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetros->width)
	{
		j = 0;
		while (j < tetros->height)
		{
			if (tetros->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetros, map, new_point(x, y), tetros->val);
	return (1);
}
