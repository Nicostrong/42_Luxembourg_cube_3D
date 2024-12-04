/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:36:31 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/04 12:56:56 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"
#include "../../includes/error.h"

int	ft_exit_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_exit_error(E_USAGE);
}

t_data	*ft_initialization(int argc, char **argv)
{
	ft_check_arg()
}