/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <athill@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:50:32 by athill            #+#    #+#             */
/*   Updated: 2024/07/05 14:53:52 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "str.h"

void	str_append(t_str *str, const char *s1, const char *s2)
{
	t_str	*new;

	if (str == NULL)
		return ;
	while (str->next)
		str = str->next;
	new = malloc(sizeof(t_str));
	if (new == NULL)
		return ;
	new->s1 = s1;
	new->s2 = s2;
	new->next = NULL;
	str->next = new;
}

void	str_print(const t_str *str)
{
	if (str == NULL)
		return ;
	while (1)
	{
		ft_putstr(str->s1);
		if (str->next)
			ft_putstr(str->s2);
		else
			break ;
		str = str->next;
	}
}

void	str_free(t_str *str)
{
	t_str	*prev;

	while (str)
	{
		prev = str;
		str = str->next;
		free(prev);
	}
}
