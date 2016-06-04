/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__init_func_by_keycode.c						:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/05/09 15:50:07 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/05/26 13:02:33 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "internal_caps.h"
#include "types.h"


#include <termcap.h>

bool	caps__init_func_by_keycode(const char *keycode, int (*func)())
{
	t_internal_context	*context;
	t_list				*new_key;

	if (keycode == NULL || func == NULL)
	{
		log_fatal("keycode %p", (void *)keycode);
		return (FALSE);
	}
	caps__get_context(&context);
	new_key = node_key__create(keycode, func);
	if (!new_key)
	{
		log_fatal("node_key__create() failed");
		return (FALSE);
	}
	list_push_back(new_key, &context->key_head);
	return (TRUE);
}
