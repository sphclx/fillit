/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:04:35 by mburl             #+#    #+#             */
/*   Updated: 2019/10/16 14:25:29 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_list			*free_list(t_list *lst)
{
	t_tetros	*tetros;
	t_list		*next;

	while (lst)
	{
		tetros = (t_tetros *)lst->content;
		next = lst->next;
		free_tetris(tetros);
		ft_memdel((void **)&lst);
		lst = next;
	}
	return (NULL);
}

void			free_tetris(t_tetros *tet)
{
	int		y;

	y = 0;
	while (y < tet->height)
	{
		ft_memdel((void **)(&(tet->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tet->pos)));
	ft_memdel((void **)&tet);
}

t_tetros		*tetris_new(char **pos, int wi, int hi, char val)
{
	t_tetros	*node;

	node = ft_memalloc(sizeof(t_tetros));
	node->pos = pos;
	node->height = hi;
	node->width = wi;
	node->val = val;
	return (node);
}

t_coords		*new_point(int x, int y)
{
	t_coords	*point;

	point = ft_memalloc(sizeof(t_coords));
	point->x = x;
	point->y = y;
	return (point);
}
