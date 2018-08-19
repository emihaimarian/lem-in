/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 02:01:34 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The ft_before_c() add spaces before if needed.
*/

void	ft_before_c(t_flags *flags, int v_len)
{
	if (flags->spaces && flags->spaces - v_len > 0)
	{
		while (flags->spaces - v_len != 0)
		{
			flags->spaces--;
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
	else if (flags->zero_base && flags->zero_base - v_len > 0)
	{
		while (flags->zero_base-- - v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
}

/*
** The ft_after_c() function adds spaces after the output when the conditions
** are met.
*/

void	ft_after_c(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}
