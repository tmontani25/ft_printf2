/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:44:47 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/04 19:48:15 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char type, void *arg)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += ft_putchar((char)arg);
	else if (type == 's')
			i += ft_putstr((char *)arg);
	else if (type == 'p')
			i += ft_handle_ptr((void *)(arg));
	else if (type == 'd' || type == 'i')
			i += ft_handle_int((int)arg);
	else if (type == 'u')
			i += ft_handle_uint((unsigned int)(arg));
	else if (type == 'x' || type == 'X')
			i += ft_handle_hex((unsigned int)(arg), type);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start(args, str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				j += write(1, "%", 1);
			else
				j += check_type(str[i], va_arg(args, void *));
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}
/*int main (void)
{
	int c;

	int nb_char_printed;

	c = 1234;
 nb_char_printed = ft_printf("%p", "");
	printf("\n\n");
	printf("nombre de char imprime: %p", "");
	return (0);
}*/