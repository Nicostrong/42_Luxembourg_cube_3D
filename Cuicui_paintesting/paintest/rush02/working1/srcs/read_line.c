/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:43:21 by athill            #+#    #+#             */
/*   Updated: 2023/12/10 16:44:51 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*add_char(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (str == 0)
	{
		free(line);
		return (0);
	}
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	read_line(int fd, char **line)
{
	char	buf[1];
	int		res;

	*line = malloc(sizeof(char));
	if (*line == 0)
		return (0);
	*line[0] = '\0';
	while (1)
	{
		res = read(fd, buf, sizeof(buf));
		if (res <= 0)
			return (0);
		if (buf[0] == '\n')
			break ;
		*line = add_char(*line, buf[0]);
		if (line == 0)
			return (0);
	}
	return (1);
}
