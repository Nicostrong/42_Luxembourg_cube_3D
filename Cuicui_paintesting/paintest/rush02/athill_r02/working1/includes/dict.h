/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:43:48 by athill            #+#    #+#             */
/*   Updated: 2024/07/05 14:59:25 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# ifndef TENS_CONNECT
#  define TENS_CONNECT " "
# endif
# ifndef HUNDREDS_CONNECT
#  define HUNDREDS_CONNECT " "
# endif

typedef struct s_dict_entry
{
	char				*num;
	char				*str;
	struct s_dict_entry	*next;
}	t_dict_entry;

typedef struct s_dict
{
	t_dict_entry	*first;
	int				error;
	const char		*tens_connect;
	const char		*hundreds_connect;
}	t_dict;

t_dict		create_dict(char *path);

void		free_dict(t_dict *dict);

const char	*dict_lookup(t_dict *dict, char *num);

const char	*dict_lookup2(t_dict *dict, char first, int zero_count);

const char	*dict_lookup_digit(t_dict *dict, char num);

#endif
