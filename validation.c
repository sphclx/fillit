/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:57:54 by jcope             #+#    #+#             */
/*   Updated: 2019/10/14 12:11:52 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Checks if there is invalid characters, length of lines,
 * for '\n' at the end of block.
 * Counts number of '#'.
 */

int		charcount(char *buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (0);
	return (count);
}

/*
 * Check if the blocks touch each other.
 */

int		adjacency_counter(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/*
 * Goes through all blocks.
 */

int		valid(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (charcount(buf + i) != 4)
			return (0);
		if (adjacency_counter(buf + i) != 6 && adjacency_counter(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
