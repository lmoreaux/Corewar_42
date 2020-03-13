/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <lmoreaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 00:27:44 by lmoreaux          #+#    #+#             */
/*   Updated: 2019/03/07 23:01:51 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int		op_lfork(t_env *p, t_proc *c)
{
	int		pc;

	pc = argint(c->save, 1, 2);
	if (!clone_proc(p, c, c->pc + pc))
	{
		ft_clean_proc(&p->process);
		return (0);
	}
	return (1);
}
