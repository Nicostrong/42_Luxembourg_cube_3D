/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athill <athill@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:44:31 by athill            #+#    #+#             */
/*   Updated: 2024/07/05 14:54:07 by athill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

typedef struct s_str
{
	const char		*s1;
	const char		*s2;
	struct s_str	*next;
}	t_str;

void	str_append(t_str *str, const char *s1, const char *s2);

void	str_print(const t_str *str);

void	str_free(t_str *str);

#endif
