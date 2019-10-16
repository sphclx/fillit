/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:22:51 by mburl             #+#    #+#             */
/*   Updated: 2019/10/16 14:25:41 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		f_sqrt(int n)
{
	int		i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}

t_map	*solve(t_list *lst)
{
	t_map	*map;
	int		size;

	size = f_sqrt(ft_lstcount(lst));
	map = map_new(size);
	while (!solve_map(map, lst))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}

int		solve_map(t_map *map, t_list *lst)
{
	int			x;
	int			y;
	t_tetros	*tetros;

	if (!lst)
		return (1);
	y = 0;
	tetros = (t_tetros *)(lst->content);
	while (y < map->size - tetros->height + 1)
	{
		x = 0;
		while (x < map->size - tetros->width + 1)
		{
			if (place(tetros, map, x, y))
			{
				if (solve_map(map, lst->next))
					return (1);
				else
					set_piece(tetros, map, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}
