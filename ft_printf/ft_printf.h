/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:15:32 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/15 21:03:42 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_format_type(char c, va_list ap, size_t *counter);
int		ft_printf(const char *format, ...);

void	ft_print_char(char c, size_t *counter);
void	ft_print_str(char *str, size_t *counter);
void	ft_print_unsigned(unsigned int n, size_t *counter);
void	ft_print_int(int nb, size_t *counter);
void	ft_print_ptr(unsigned long ptr, size_t *counter);
void	ft_print_hex(unsigned long n, char c, size_t *counter);

#endif