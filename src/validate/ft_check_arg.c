/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:36:31 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/04 13:37:25 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

int	ft_exit_error(char *str, t_data *data)
{
	ft_putendl_fd(str, 2);
	if (data)
		ft_errclose(data);
	exit(EXIT_FAILURE);
}

void	ft_check_arg(int argc)
{
	if (argc != 2)
		ft_exit_error(E_USAGE, NULL);
}

/*
 *	A MODIFIER
 *	CHECK ARG
 *	CHECK ARGV
 *	CHECK MAP
 */
t_data	*ft_initialization(int argc, char **argv)
{
	t_data	*data;

	ft_check_arg(argc);
	(void) argv;
	data = NULL;
	return (data);
}