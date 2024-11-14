/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:51:09 by athill            #+#    #+#             */
/*   Updated: 2024/07/05 14:26:53 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "dict.h"
#include "str.h"

int		num_to_str(t_dict *dict, t_str *str, char *num, int len);

int	all_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] != '0')
			return (0);
	return (1);
}

int	num_simple(t_dict *dict, t_str *str, char *num)
{
	const char	*part;

	if (ft_strcmp(num, "00") == 0)
		part = dict_lookup(dict, "0");
	else
		part = dict_lookup(dict, num);
	if (part == NULL)
		return (-1);
	str_append(str, part, " ");
	return (0);
}

int	num_len2(t_dict *dict, t_str *str, char *num)
{
	const char	*part1;
	const char	*part2;

	if (num[0] != '0')
	{
		part1 = dict_lookup2(dict, num[0], 1);
		if (part1 == NULL)
			return (-1);
		str_append(str, part1, dict->tens_connect);
	}
	part2 = dict_lookup_digit(dict, num[1]);
	if (part2 == NULL)
		return (-1);
	str_append(str, part2, " ");
	return (0);
}

int	num_len3(t_dict *dict, t_str *str, char *num)
{
	const char	*part1;
	const char	*part2;

	if (num[0] == '0')
		return (num_to_str(dict, str, &num[1], 2));
	part1 = dict_lookup_digit(dict, num[0]);
	part2 = dict_lookup2(dict, '1', 2);
	if (part1 == NULL || part2 == NULL)
		return (-1);
	str_append(str, part1, " ");
	if (all_zeros(&num[1]))
	{
		str_append(str, part2, " ");
		return (0);
	}
	str_append(str, part2, dict->hundreds_connect);
	return (num_to_str(dict, str, &num[1], 2));
}

int	num_to_str(t_dict *dict, t_str *str, char *num, int len)
{
	const char	*part2;
	char		part1_num[4];
	int			part1_len;

	if (len == 0)
		return (0);
	if (len == 1 || (len == 2 && (num[0] == '1' || num[1] == '0')))
		return (num_simple(dict, str, num));
	if (len == 2)
		return (num_len2(dict, str, num));
	if (len == 3)
		return (num_len3(dict, str, num));
	part1_len = (len + 2) % 3 + 1;
	ft_strncpy(part1_num, num, part1_len);
	part1_num[part1_len] = '\0';
	part2 = dict_lookup2(dict, '1', len - part1_len);
	if (all_zeros(part1_num))
		return (num_to_str(dict, str, &num[part1_len], len - part1_len));
	if (part2 == NULL || num_to_str(dict, str, part1_num, part1_len) == -1)
		return (-1);
	str_append(str, part2, " ");
	if (all_zeros(&num[part1_len]))
		return (0);
	return (num_to_str(dict, str, &num[part1_len], len - part1_len));
}
