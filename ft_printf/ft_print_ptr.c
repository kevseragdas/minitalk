/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:59:29 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/19 12:26:35 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long ptr, size_t *counter)
{
	if (ptr == 0)
	{
		ft_print_str("(nil)", counter);
	}
	else
	{
		ft_print_str("0x", counter);
		ft_print_hex(ptr, 'x', counter);
	}
}
