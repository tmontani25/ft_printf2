/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:45:20 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/04 19:48:13 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_handle_uint(unsigned int n);
int		ft_handle_int(int n);
int		ft_lenght_hex(unsigned long nb);
int		ft_itoa_hex(unsigned long nb, char X_or_x);
char	*ft_putnbr_hex(unsigned long nb, char X_or_x, char *str);
int		ft_handle_ptr(void *ptr);
int		ft_handle_hex(unsigned int nb, char X_or_x);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putstr_nreverse(char *str);
char	*fill_hex_str(char *str, unsigned long nb, char X_or_x);

#endif