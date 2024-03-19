/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:46:45 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/08 16:39:26 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_hexa_len(unsigned int n);
void	ft_put_hexa(unsigned int n, const char format);
int		ft_print_hex(unsigned int n, const char format);
int		ft_ptr_len(unsigned long n);
void	ft_put_ptr(unsigned long n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_unsigned_len(unsigned int n);
void	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
void	ft_putstr(char *s);
int		ft_printstr(char *s);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_printf(const char *str, ...);

#endif
