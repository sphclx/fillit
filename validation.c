/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:01:01 by abenton           #+#    #+#             */
/*   Updated: 2019/10/10 19:05:20 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	while (i < 19)
	{
		if (buff[i] && buff[i] != '\n' && buff[i] != '#' && buff[i] != '.')
			return (0);
		if (buff[i] == '\n' && (i % 5 == 0))
			return (0);
		if (buff[i] == '#')
			count++;
		i++;
	}
	if (!buff[i] || buff[i] != '\n')
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
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if (i + 1 <= 19 && buff[i] == '#')
				count++;
			if (i - 1 >= 0 && buff[i] == '#')
				count++;
			if (i - 5 <= 0 && buff[i] == '#')
				count++;
			if (i + 5 >= 19 && buff[i] == '#')
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
		if (touch_blocks(buff + i) != 6 || touch_blocks(buff + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
