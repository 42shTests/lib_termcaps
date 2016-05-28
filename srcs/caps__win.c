/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps__win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:50:33 by abombard          #+#    #+#             */
/*   Updated: 2016/05/21 18:53:30 by abombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_caps.h"

#include <termcap.h>

extern size_t	caps__win(const char *cmd)
{
	t_internal_context	*context;

	if (!cmd)
	{
		log_fatal("cmd %p", (void *)cmd);
		return 0;
	}
	caps__get_context(&context);
//	if (!tgetent(context->termbuffer, context->termtype))
//		log_fatal("tgetent() failed %s", "");
	return (tgetnum((char *)cmd));
}
