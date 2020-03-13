/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <lmoreaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 00:44:08 by lmoreaux          #+#    #+#             */
/*   Updated: 2019/03/06 21:47:00 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int	op_zjmp(t_env *p, t_proc *c)
{
	int		pc;

	(void)p;
	if (c->save[0] == 15 || c->save[0] == 12)
		pc = 3;
	else
		pc = (argint(c->save, 1, 2) % IDX_MOD);
	if (c->carry == 1)
		c->jp = pc;
	return (1);
}
