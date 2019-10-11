/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:01:01 by abenton           #+#    #+#             */
/*   Updated: 2019/10/11 16:27:08 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
 * Checks if there is invalid characters, length of lines,
 * for '\n' at the end of block.
 * Counts number of '#'.
 */

int		charact(char *buff)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (ft_strlen(buff) != 20)
		return (0);
	while (i < 19)
	{
		if (buff[i] && buff[i] != '\n' && buff[i] != '#' && buff[i] != '.')
			return (0);
		if (buff[i] == '\n' && (i % 5 != 4))
			return (0);
		if (buff[i] == '#')
			count++;
		i++;
	}
	if (buff[i] && buff[i] != '\n')
		return (0);
	return (count);
}

/*
 * Check if the blocks touch each other.
 */

int		touch_blocks(char *buff)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			if (i + 1 <= 19 && buff[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buff[i - 1] == '#')
				count++;
			if (i - 5 >= 0 && buff[i - 5] == '#')
				count++;
			if (i + 5 <= 19 && buff[i + 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/* 
 * Goes through all blocks.
 */

int		valid(char *buff, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (charact(buff + i) != 4)
			return (0);
		if (touch_blocks(buff + i) != 6 && touch_blocks(buff + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
 }
