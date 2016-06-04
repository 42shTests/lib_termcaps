/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__init_func.c									:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/05/09 15:49:10 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/05/26 13:02:22 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "internal_caps.h"
#include "types.h"
#include <termcap.h>

bool	caps__init_func(const char *tcapcode, int (*func)())
{
	t_internal_context	*context;
	char				*keycode;
	t_list				*new_key;

	if (!tcapcode || !func)
	{
		log_fatal("tcapcode %p func %p", (void *)tcapcode, (void *)func);
		return (false);
	}
	caps__get_context(&context);
	keycode = tgetstr(tcapcode, &context->buffaddr);
	if (!keycode)
	{
		log_fatal("Could not intialize %s", tcapcode);
		return (false);
	}
	new_key = node_key__create(keycode, func);
	if (!new_key)
	{
		log_fatal("node_key__create() failed");
		return (NULL);
	}
	list_push_back(new_key, &context->key_head);
	return (true);
}
