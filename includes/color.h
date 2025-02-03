/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:06:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/03 11:45:38 by nfordoxc         ###   Luxembourg.lu     */
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

/*
 *	Pixel color
 */

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define PINK		0xFFC0CB
# define BROWN		0xA52A2A
# define GREY		0x808080
# define GOLD		0xFFD700
# define SILVER		0xC0C0C0
# define SKY		0x87CEEB
# define LIME		0x00FF00
# define MAROON		0x800000
# define OLIVE		0x808000
# define TEAL		0x008080
# define NAVY		0x000080
# define VIOLET		0xEE82EE

#endif