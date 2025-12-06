/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:13:53 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/19 12:25:38 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned long n, char c, size_t *counter)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_print_char('0', counter);
		return ;
	}
	if (n < 16)
	{
		ft_print_char(base[n], counter);
	}
	else
	{
		ft_print_hex(n / 16, c, counter);
		ft_print_hex(n % 16, c, counter);
	}
}
