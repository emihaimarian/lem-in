/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by mienache          #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The ft_s() function launchs the conversion for s specifier.
*/

static int	ft_conv_s_case1(char *lpa, t_flags flags)
{
	int		ln;

	ln = flags.zero;
	ft_before_str(&flags, 0);
	ft_put_precision_str(flags, lpa, -1);
	ft_after_str(&flags, 0);
	return (ln);
}

int			ft_conv_s_case2(t_flags flags)
{
	int		ln;

	ln = 6;
	flags.preci > 0 && flags.preci < ln ? ln = flags.preci : 0;
	ft_before_str(&flags, ln);
	ft_put_precision_str(flags, "(null)", ln);
	ft_after_str(&flags, ln);
	return (ln + flags.spaces_count);
}

static int	ft_conv_s_case3(char *lpa, t_flags flags)
{
	int		ln;

	ln = flags.zero;
	ft_before_str(&flags, 0);
	ft_put_precision_str(flags, lpa, -1);
	ft_after_str(&flags, 0);
	return (ln + flags.spaces_count);
}

void		ft_star_part(t_flags *flags)
{
	if (flags->preci < 0)
		flags->preci = -flags->preci;
}

int			ft_s(va_list pa, t_flags flags)
{
	char	*local_pa;
	int		ln;

	if (flags.l == 1)
		return (ft_ls(pa, flags));
	if (flags.star == 1 && flags.prio[flags.star] == 2)
		ft_star_part(&flags);
	local_pa = va_arg(pa, char *);
	if (local_pa == NULL && flags.preci == -1)
		return (ft_conv_s_case1(local_pa, flags));
	else if (local_pa == NULL && flags.preci >= 0)
		return (ft_conv_s_case2(flags));
	else if (local_pa != NULL && flags.preci == -1)
		return (ft_conv_s_case3(local_pa, flags));
	ln = ft_strlen(local_pa);
	flags.preci > 0 && flags.preci < ln ? ln = flags.preci : 0;
	ft_before_str(&flags, ln);
	ft_put_precision_str(flags, local_pa, ln);
	ft_after_str(&flags, ln);
	return (ln + flags.spaces_count);
}
