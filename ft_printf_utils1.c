/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:07:01 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/04 19:48:20 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_handle_uint(unsigned int n)
{
	if (n < 0)
		n = n * (-1);
	if (n >= 10)
		return (ft_handle_uint(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}

int	ft_handle_int(int n)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		len += ft_handle_int(nbr / 10);
		nbr %= 10;
	}
	len += ft_putchar(nbr + '0');
	return (len);
}
