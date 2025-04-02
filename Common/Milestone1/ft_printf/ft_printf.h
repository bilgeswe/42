/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:34:57 by bakpulat          #+#    #+#             */
/*   Updated: 2024/12/18 12:04:02 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_check(va_list args, char c);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putadress(unsigned long nb);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthexadecimal_lowercase(unsigned int nb);
int	ft_puthexadecimal_uppercase(unsigned int nb);
int	ft_putptr(unsigned long long c);

#endif
