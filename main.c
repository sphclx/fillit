/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:54:28 by abenton           #+#    #+#             */
/*   Updated: 2019/10/11 14:37:25 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static  int     read_tetros(int fd)
{
    char	buff[6];
    int		ret;
	int		i;
	char	*temp_tetros;
	char	*temp_string;
	
	temp_string = ft_strnew(1);
    while ((ret = read(fd, buff, 5)) > 0)
	{
		buff[ret] = '\0';
		temp_string = ft_strjoin(temp_string, buff);
	}
	ft_putnbr(valid(temp_string, ft_strlen(temp_string)));
	return (0);
}

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file\n");
		return (-1);
	}	
	fd = open(av[1], O_RDONLY);
	read_tetros(fd);
}
