/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:04:52 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/22 10:35:54 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_get_color(int t, int r, int g, int b)
 * </summary>
 *
 * <description>
 * 	ft_get_color return the hexa value of the color of the pixel.
 * </description>
 *
 * <param type="int" name="t">alpha canal</param>
 * <param type="int" name="r">red canal</param>
 * <param type="int" name="g">green canal</param>
 * <param type="int" name="b">blue canal</param>
 *
 * <return>
 * 	the color of the pixel in format AARRGGBB.
 * </return>
 *
 */
int	ft_get_color(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}