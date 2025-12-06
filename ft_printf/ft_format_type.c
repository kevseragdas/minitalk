/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:28:52 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/15 18:27:09 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_type(char c, va_list ap, size_t *counter)
{
	if (c == 'c')
		ft_print_char(va_arg(ap, int), counter);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(ap, int), counter);
	else if (c == 's')
		ft_print_str(va_arg(ap, char *), counter);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(ap, unsigned int), c, counter);
	else if (c == 'u')
		ft_print_unsigned(va_arg(ap, unsigned int), counter);
	else if (c == 'p')
		ft_print_ptr(va_arg(ap, unsigned long), counter);
	else if (c == '%')
		ft_print_char('%', counter);
	return (*counter);
}
