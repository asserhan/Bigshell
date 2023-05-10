/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:40:15 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/07 11:44:32 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *str, ...);
char		*putchar_count(char *s, char c, int *control);
char		*put_str(char *s, char *arg, int *control);
char		*put_pointer(char *s, unsigned long pointer, int *control);
char		*put_dicimal(char *s, long long nbr, int *control);
char		*put_unsigned(char *s, unsigned int nbr, int *control);
char		*put_hexa(char *s, long long nbr, int *control);
char		*flag_anal(char *s, va_list args, int *controls);
char		*testing_flags(char *s, va_list args, int *controls);
#endif