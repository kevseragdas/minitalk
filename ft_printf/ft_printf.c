/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:15:26 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/19 16:44:49 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			ft_format_type(*(++format), ap, &count);
			format++;
		}
		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(ap);
	return (count);
}
