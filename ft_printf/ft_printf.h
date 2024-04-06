/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:51:12 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/04 16:36:35 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_hexaconvert(unsigned long long n, int c);
int		ft_putstr(const char *s);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_unputnbr(unsigned long long n);
int		ft_printaddress(unsigned long long n);
int		ft_count(unsigned long long n);
int		ft_printf(const char *str, ...);

#endif
