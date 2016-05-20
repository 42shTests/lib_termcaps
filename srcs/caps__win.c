/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__win.c										:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/04/01 17:55:54 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/04/01 17:55:56 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "internal_caps.h"
#include "log.h"
#include <termcap.h>

extern size_t	caps__win(const char *cmd)
{
	t_internal_context	*context;

	if (!cmd)
		FATAL("cmd %p", (void *)cmd);
	caps__get_context(&context);
	if (!tgetent(context->termbuffer, context->termtype))
		FATAL("tgetent() failed %s", "");
	return (tgetnum((char *)cmd));
}
