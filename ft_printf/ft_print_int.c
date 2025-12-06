/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:46:58 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/15 18:27:15 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int nb, size_t *counter)
{
	if (nb == -2147483648)
	{
		ft_print_int((nb / 10), counter);
		ft_print_char('8', counter);
	}
	else if (nb < 0)
	{
		ft_print_char('-', counter);
		ft_print_int(-nb, counter);
	}
	else
	{
		if (nb >= 10)
		{
			ft_print_int((nb / 10), counter);
		}
		ft_print_char(((nb % 10) + 48), counter);
	}
}
