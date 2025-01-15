/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:06:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/15 11:31:22 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*
 *	Reset color
 */

# define RESET		"\033[0m"

/*
 *	Bold color
 */

# define BRED		"\033[1;31m"
# define BGREEN		"\033[1;32m"
# define BYELLOW	"\033[1;93m"
# define BGOLD		"\033[1;33m"
# define BBLUE		"\033[1;34m"
# define BMAGENTA	"\033[1;35m"
# define BCYAN		"\033[1;36m"

/*
 *	Blink color
 */

# define REDC		"\033[5;31m"
# define GREENC		"\033[5;32m"
# define YELLOWC	"\033[5;93m"
# define GOLDC		"\033[5;33m"
# define BLUEC		"\033[5;34m"
# define MAGENTAC	"\033[5;35m"
# define CYANC		"\033[5;36m"

#endif