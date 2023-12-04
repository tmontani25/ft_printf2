/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:44:57 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/04 20:11:37 by tmontani         ###   ########.fr       */
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

int	ft_handle_ptr(void *ptr)
{
	int	j;

	j = 0;
	if (ptr == NULL)
	{
		ft_putstr("0x0");
		return (3);
	}
	j += ft_putstr("0x");
	j += ft_itoa_hex((unsigned long)ptr, 'x');
	return (j);
}
