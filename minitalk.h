/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:43:59 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/06 14:06:36 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_server
{
	int				bit_counter;
	unsigned char	chr;
}	t_server;

int	ft_count(char *s);
int	ft_atoi(const char *nptr);

#endif