/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:00:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 13:54:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_strequal(const char *s1, const char *s2)
 * </summary>
 *
 * <description>
 *	ft_strcmp compare if two strings are equal or not.
 * </description>
 *
 * <param type="const void *" name="s1">string 1</param>
 * <param type="const void *" name="s2">string 2</param>
 *
 * <return>
 *	1, if s1 == s2,
 *	0, if s1 != s2,
 * </return>
 *
 */

int	ft_strequal(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}
