/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:13:06 by athill            #+#    #+#             */
/*   Updated: 2024/07/05 15:00:00 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "ft.h"
#include "dict.h"

int	parse_dict(int fd, t_dict *dict);

t_dict	create_dict(char *path)
{
	int				fd;
	t_dict			dict;

	dict.first = NULL;
	dict.error = 0;
	dict.tens_connect = TENS_CONNECT;
	dict.hundreds_connect = HUNDREDS_CONNECT;
	fd = open(path, 0);
	if (fd >= 0)
		if (parse_dict(fd, &dict) == 0)
			free_dict(&dict);
	return (dict);
}

void	free_dict(t_dict *dict)
{
	t_dict_entry	*entry;

	while (dict->first)
	{
		entry = dict->first;
		free(entry->num);
		free(entry->str);
		dict->first = entry->next;
		free(entry);
	}
}

const char	*dict_lookup(t_dict *dict, char *num)
{
	t_dict_entry	*entry;

	entry = dict->first;
	while (entry)
	{
		if (ft_strcmp(num, entry->num) == 0)
			return (entry->str);
		entry = entry->next;
	}
	dict->error = 1;
	return (NULL);
}

const char	*dict_lookup2(t_dict *dict, char first, int zero_count)
{
	int				j;
	char			*num;
	t_dict_entry	*entry;

	entry = dict->first;
	while (entry)
	{
		num = entry->num;
		if (num[0] == first)
		{
			j = 1;
			while (num[j] == '0' && j <= zero_count)
				j++;
			if (j == zero_count + 1 && num[j] == '\0')
				return (entry->str);
		}
		entry = entry->next;
	}
	dict->error = 1;
	return (NULL);
}

const char	*dict_lookup_digit(t_dict *dict, char num)
{
	t_dict_entry	*entry;

	entry = dict->first;
	while (entry)
	{
		if (entry->num[0] == num && entry->num[1] == '\0')
			return (entry->str);
		entry = entry->next;
	}
	dict->error = 1;
	return (NULL);
}
