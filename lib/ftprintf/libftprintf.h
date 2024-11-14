/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:28:48 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/31 01:46:32 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

/*
 *Fonction ft_printf
 */
int		ft_printf(const char *str, ...);

/*
 *Fonction put fd
 */
int		ft_putchar_fd_ptf(char c, int fd);
int		ft_putstr_fd_ptf(char *s, int fd, int len);
int		ft_puthexa_fd_ptf(unsigned int hex, char x, int fd, int len);
int		ft_puthexaptr_fd_ptf(unsigned long hex, int fd, int len);
int		ft_putnbr_fd_ptf(int n, int fd, int len);
int		ft_putunsnbr_fd_ptf(unsigned int n, int fd, int len);
int		ft_putptr_fd_ptf(void *ptr, int fd, int len);

/*
 * Gestion de la sortie
 */
int		ft_printf_error(char *str);

#endif
