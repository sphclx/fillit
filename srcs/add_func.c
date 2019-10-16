/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:28:42 by mburl             #+#    #+#             */
/*   Updated: 2019/10/16 14:21:57 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void			min_max(char *str, t_coords *min, t_coords *max)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_tetros		*get_piece(char *str, char val)
{
	t_coords	*mi;
	t_coords	*max;
	char		**pos;
	int			i;
	t_tetros	*tetros;

	mi = new_point(3, 3);
	max = new_point(0, 0);
	min_max(str, mi, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - mi->y + 1));
	i = 0;
	while (i < max->y - mi->y + 1)
	{
		pos[i] = ft_strnew(max->x - mi->x + 1);
		ft_strncpy(pos[i], str + (mi->x) + (i + mi->y) * 5, max->x - mi->x + 1);
		i++;
	}
	tetros = tetris_new(pos, max->x - mi->x + 1, max->y - mi->y + 1, val);
	ft_memdel((void **)&mi);
	ft_memdel((void **)&max);
	return (tetros);
}

t_list			*read_tetros(int fd)
{
	char		*buf;
	int			count;
	t_list		*lst;
	t_tetros	*tetris;
	char		letter;

	buf = ft_strnew(21);
	lst = NULL;
	letter = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if ((tetris = get_piece(buf, letter++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(lst));
		}
		ft_lstadd(&lst, ft_lstnew(tetris, sizeof(*tetris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (free_list(lst));
	ft_lstrev(&lst);
	return (lst);
}
