/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:39:54 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/15 18:27:23 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, size_t *counter)
{
	int	i;

	if (str == NULL)
	{
		ft_print_str("(null)", counter);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_print_char(str[i], counter);
		i++;
	}
}
