/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:55:03 by abenton           #+#    #+#             */
/*   Updated: 2019/10/10 18:50:54 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

/*
 * structure from piscine d11/ex01
   
typedef struct		s_list
{
	void			*data;
	struct s_list   *next;
}					t_list;

*/

typedef struct	s_tetris
{
	int block;

}				t_tetris;

int		valid(char *buff, int size);

#endif
