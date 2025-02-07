/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:36:31 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/07 11:11:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_check_cub(char *path)
 * </summary>
 *
 * <description>
 * 	ft_check_cub check the extension of the map passed in argument.
 * </description>
 *
 * <param type="char *" name="path">path with the map</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */
static int	ft_check_cub(char *path)
{
	int		i;

	i = ft_strlen(path);
	if (i < 5)
		return (0);
	if (access(path, F_OK) == -1)
		ft_perror_exit(E_EXIST, NULL);
	if (path[i - 4] != '.' || path[i - 3] != 'c' || path[i - 2] != 'u' || \
			path[i - 1] != 'b')
		return (0);
	return (1);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_check_not_cub(char *path)
 * </summary>
 *
 * <description>
 * 	ft_check_not_cub check if the file is really a .cub file and not a hidden 
 * 	file called cub.
 * </description>
 *
 * <param type="char *" name="path">path with the map</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */
static int	ft_check_not_cub(char *path)
{
	int		index;
	char	**array;

	index = 0;
	array = ft_split(path, '/');
	while (array[index])
		index++;
	if (ft_strlen(array[--index]) < 5)
		return (ft_free_array(array), 0);
	ft_free_array(array);
	return (1);
}

/*
 * <cat>cube_3D/cat>
 *
 * <summary>
 * 	int	ft_check_open_cub(char *path)
 * </summary>
 *
 * <description>
 * 	ft_check_open_cub check if the file exist and can be reading. 
 * 	file called ber.
 * </description>
 *
 * <param type="char *" name="path">path with the map</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */
static int	ft_check_open_cub(char *path)
{
	if (access(path, F_OK) == -1)
		ft_perror_exit(E_EXIST, NULL);
	if (access(path, R_OK) == -1)
		return (0);
	return (1);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_check_arg(int argc, char *argv)
 * </summary>
 *
 * <description>
 * 	ft_check_arg check the number of argument passed at the program.
 * 	check if the map is cub file.
 * 	check if the file isn't an empty file.
 * 	check if the file exist or not.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char *" name="argv">array of arguments</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */
int	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_perror_exit(E_USAGE, NULL);
	if (!ft_check_cub(argv[argc - 1]))
		ft_perror_exit(E_CUB, NULL);
	if (!ft_check_not_cub(argv[argc - 1]))
		ft_perror_exit(E_HIDDEN, NULL);
	if (!ft_check_open_cub(argv[argc - 1]))
		ft_perror_exit(E_OPEN, NULL);
	return (1);
}
