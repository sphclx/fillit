/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:04:49 by mburl             #+#    #+#             */
/*   Updated: 2019/10/16 14:22:52 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		main(int ac, char **av)
{
	t_list		*lst;
	t_map		*map;

	if (ac != 2)
		ft_putstr_err("usage: fillit input_file\n");
	if ((lst = read_tetros(open(av[1], O_RDONLY))) == NULL)
		ft_putstr_err("error\n");
	map = solve(lst);
	print_map(map);
	free_map(map);
	free_list(lst);
	return (0);
}
