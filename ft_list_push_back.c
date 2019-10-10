/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:07:00 by abenton           #+#    #+#             */
/*   Updated: 2019/10/10 14:47:04 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (begin_list && *begin_list)
	{
		tmp = *begin_list;
		while ((*tmp).next)
			tmp = (*tmp).next;
		(*tmp).next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
