/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:30:38 by athill            #+#    #+#             */
/*   Updated: 2024/07/05 12:28:59 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "dict.h"
#include "str.h"

int	num_to_str(t_dict *dict, t_str *str, char *num, int len);

t_dict	dict_init(int argc, char **argv)
{
	if (argc == 2)
		return (create_dict("numbers.dict"));
	return (create_dict(argv[1]));
}

char	*num_init(int argc, char **argv)
{
	char	*num;
	int		i;

	if (argc == 2)
		num = argv[1];
	else
		num = argv[2];
	if (*num == '\0')
		return (NULL);
	i = -1;
	while (num[++i] != '\0')
		if (num[i] < '0' || num[i] > '9')
			return (NULL);
	return (num);
}

void	convert(t_dict *dict, char *num)
{
	t_str	str;
	int		res;

	str.next = NULL;
	while (*num == '0')
		num++;
	if (*num == '\0')
		num--;
	res = num_to_str(dict, &str, num, ft_strlen(num));
	if (dict->error)
		ft_putstr("Dict Error");
	else if (res == -1 || str.next == NULL)
		ft_putstr("Error");
	else
		str_print(str.next);
	str_free(str.next);
}

int	main(int argc, char **argv)
{
	t_dict	dict;
	char	*num;

	if (argc == 1 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	num = num_init(argc, argv);
	if (num == NULL)
	{
		ft_putstr("Error\n");
		return (0);
	}
	dict = dict_init(argc, argv);
	if (dict.first == NULL)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	convert(&dict, num);
	ft_putstr("\n");
	free_dict(&dict);
	return (0);
}
