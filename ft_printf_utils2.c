/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:44:57 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/04 19:48:17 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_hex(unsigned long nb, char X_or_x, char *str)
{
	char	*hex_upper;
	char	*hex_lower;
	int		i;

	i = 0;
	hex_upper = "0123456789ABCDEF";
	hex_lower = "012456789abcdef";
	while (nb > 0)
	{
		if (X_or_x == 'X')
		{
			str[i] = hex_upper[nb % 16];
			nb = nb / 16;
			i++;
		}
		else if (X_or_x == 'x')
		{
			str[i] = hex_lower[nb % 16];
			nb = nb / 16;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

int	ft_putstr_nreverse(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		j += write(1, &str[i], 1);
		i--;
	}
	return (j);
}
