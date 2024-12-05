/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:06:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/05 07:09:45 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*
 *	Reset color
 */

# define NOCOLOR	"\033[0m"

/*
 *	Bold color
 */

# define REDG		"\033[1;31m"
# define GREENG		"\033[1;32m"
# define YELLOWG	"\033[1;93m"
# define GOLDG		"\033[1;33m"
# define BLUEG		"\033[1;34m"
# define MAGENTAG	"\033[1;35m"
# define CYANG		"\033[1;36m"

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