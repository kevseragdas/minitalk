/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:44:23 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/03 18:48:39 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	opt;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	opt = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			opt *= -1;
		i++;
	}
	num = 0;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (opt * num);
}

int	ft_count(char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
