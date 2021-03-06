/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by mienache          #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_flags(t_flags *flag)
{
	flag->hash = 0;
	flag->zero = 0;
	flag->spaces = 0;
	flag->preci = 0;
	flag->l = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->empty = 0;
	flag->spaces_count = 0;
	flag->preci_diff = 0;
	flag->display = 0;
	flag->temp = 0;
	flag->star = 0;
	flag->prio[0] = 0;
	flag->prio[1] = 0;
	flag->prio[2] = 0;
}

static void		ft_init_table(int (*tab[128])())
{
	tab['s'] = &ft_s;
	tab['S'] = &ft_ls;
	tab['p'] = &ft_p;
	tab['d'] = &ft_d_i;
	tab['D'] = &ft_ld;
	tab['i'] = &ft_d_i;
	tab['o'] = &ft_o;
	tab['O'] = &ft_lo;
	tab['u'] = &ft_u;
	tab['U'] = &ft_lu;
	tab['x'] = &ft_x;
	tab['X'] = &ft_lx;
	tab['c'] = &ft_c;
	tab['C'] = &ft_lc;
	tab['f'] = &ft_f;
	tab['F'] = &ft_f;
}

static int		ft_load_flags(char *str, int index, t_flags *flag)
{
	ft_init_flags(flag);
	while (ft_is_printf(str[index]) == 0)
	{
		str[index] == '#' ? flag->hash = ft_flag_bool(&index) : 0;
		str[index] == '-' ? flag->minus = ft_flag_bool(&index) : 0;
		str[index] == '.' ? flag->preci = ft_flag_preci(str, &index, flag) : 0;
		str[index] == ' ' ? flag->empty = ft_flag_bool(&index) : 0;
		str[index] == '+' ? flag->plus = ft_flag_bool(&index) : 0;
		str[index] == '0' ? flag->zero = ft_flag_zero(str, &index, flag) : 0;
		str[index] == '!' ? flag->display = ft_flag_bool(&index) : 0;
		str[index] == '*' ? flag->star += ft_flag_star_bool(&index, flag) : 0;
		if (str[index] > '0' && str[index] <= '9')
			flag->spaces = ft_flag_spaces(str, &index);
		if (str[index] == 'l' || str[index] == 'h' || str[index] == 'j'
			|| str[index] == 'z')
			flag->l = ft_flag_length(str, &index, *flag);
	}
	flag->zero_base = flag->zero;
	(flag->minus == 1 && flag->zero != 0) ? flag->spaces = flag->zero : 0;
	(flag->minus == 1 && flag->zero != 0) ? flag->zero = 0 : 0;
	(flag->minus == 1) ? flag->spaces = -flag->spaces : 0;
	(flag->plus == 1 && flag->empty == 1) ? flag->empty = 0 : 0;
	return (index);
}

void			ft_flag_star(va_list pa, t_flags *flag, int index)
{
	int		value;

	value = va_arg(pa, long);
	if (flag->prio[index] == 1 && flag->zero <= 0)
	{
		flag->zero = value;
		flag->zero_base = flag->zero;
	}
	else if (flag->prio[index] == 3 && flag->preci <= 0)
	{
		if (value < 0)
		{
			flag->preci = flag->zero;
			flag->zero = 0;
			flag->zero_base = 0;
		}
		else
		{
			flag->preci = value;
			(flag->preci == 0) ? flag->preci = -1 : 0;
		}
	}
	else if (flag->spaces <= 0)
		flag->spaces = flag->minus == 1 ? -value : value;
	flag->star -= 1;
}

int				ft_printf_conv(char *str, va_list *ap, int *value, int index)
{
	int			(*tab[128])(va_list, t_flags);
	int			i;
	int			j;
	t_flags		flags;

	i = 0;
	index = ft_load_flags(str, index, &flags);
	ft_init_table(tab);
	while (flags.star > 0)
	{
		ft_flag_star(*ap, &flags, i);
		i++;
	}
	if (ft_is_printf(str[index]) == 2)
		*value += ft_conv_char(flags, str[index]);
	else if (str[index] == '%')
		*value += ft_conv_percent(flags);
	else if (ft_is_printf(str[index]) == 1 && str[index] != '%')
	{
		if ((j = tab[(int)str[index]](*ap, flags)) == -1)
			return (-1);
		*value += j;
	}
	*value -= 1;
	return (index);
}
