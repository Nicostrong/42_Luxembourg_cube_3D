/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:38:59 by athill            #+#    #+#             */
/*   Updated: 2024/07/05 11:47:35 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "get_next_line.h"
#include "dict.h"

int	parse_num(char *line, t_dict_entry *entry)
{
	int	i;
	int	n;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '+')
		i++;
	n = i;
	if (line[i] == '-')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	entry->num = malloc((i - n + 1) * sizeof(char));
	if (entry->num == 0)
		return (-1);
	ft_strncpy(entry->num, &line[n], i - n);
	entry->num[i - n] = '\0';
	while (line[i] != '\0' && line[i] != ':')
		i++;
	return (i);
}

void	parse_str(char *line, t_dict_entry *entry)
{
	int	i;
	int	n;

	i = 0;
	while (line[i] == ' ')
		i++;
	n = i;
	while (line[i] != '\0')
	{
		if (line[i] < 32 || line[i] > 126)
			return ;
		i++;
	}
	if (i == n)
		return ;
	entry->str = malloc((i - n + 1) * sizeof(char));
	if (entry->str == 0)
		return ;
	ft_strncpy(entry->str, &line[n], i - n);
	entry->str[i - n] = '\0';
}

t_dict_entry	*parse_line(char *line)
{
	t_dict_entry	*entry;
	int				i;

	entry = malloc(sizeof(t_dict_entry));
	if (entry == 0)
		return (0);
	entry->num = 0;
	entry->str = 0;
	entry->next = 0;
	i = parse_num(line, entry);
	if (i == -1 || line[i] == '\0')
		return (entry);
	i++;
	parse_str(&line[i], entry);
	return (entry);
}

char	*gnl(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	parse_dict(int fd, t_dict *dict)
{
	char			*line;
	t_dict_entry	*entry;

	while (1)
	{
		line = gnl(fd);
		if (line == NULL)
			return (1);
		if (line[0] == '\0')
			free(line);
		else
		{
			entry = parse_line(line);
			free(line);
			if (entry == 0)
				return (0);
			entry->next = dict->first;
			dict->first = entry;
			if (entry->num == 0 || entry->str == 0)
				return (0);
		}
	}
}
