/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:48 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/04 20:11:06 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*fill_hex_str(char *str, unsigned long nb, char X_or_x)
{
	char	*hex_upper;
	char	*hex_lower;
	int		i;

	i = 0;
	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	while (nb > 0)
	{
		if (X_or_x == 'x')
		{
			str[i] = hex_lower[nb % 16];
		nb /= 16;
		i++;
		}
		else if (X_or_x == 'X')
		{
			str[i] = hex_upper[nb % 16];
		nb /= 16;
		i++;
		}
		str[i] = '\0';
	}
	return (str);
}

int	ft_itoa_hex(unsigned long nb, char X_or_x)
{
	char	*str;
	char	*hexa_upper;
	char	*hexa_lower;
	int		i;
	int		j;

	hexa_lower = "0123456789abcdef";
	hexa_upper = "0123456789ABCDEF";
	i = 0;
	j = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	str = (char *)malloc(sizeof(char) * 17);
	if (!str)
		return (0);
	str = fill_hex_str(str, nb, X_or_x);
	j += ft_putstr_nreverse(str);
	free(str);
	return (j);
}

int	ft_lenght_hex(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	len--;
	return (len);
}

int	ft_handle_hex(unsigned int nb, char X_or_x)
{
	int	len;
	int	j;

	j = 0;
	len = ft_lenght_hex(nb);
	j += ft_itoa_hex(nb, X_or_x);
	return (j);
}
/*int main(void)
{
	char c;
	char *ptr;

	ptr = &c;
	printf("\n\n");
	printf("vraie adresse de ptr %p\n\n", ptr);
	ft_handle_ptr(ptr);
}*/