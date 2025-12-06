/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:46:35 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/15 18:27:21 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int n, size_t *counter)
{
	if (n > 9)
		ft_print_unsigned(n / 10, counter);
	ft_print_char(n % 10 + '0', counter);
}
