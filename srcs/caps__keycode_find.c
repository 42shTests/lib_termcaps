/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__keycode_find.c								:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/04/01 17:53:14 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/04/01 17:54:18 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "types.h"

#include "internal_caps.h"

bool	caps__keycode_find(const size_t in_keycode_size, const char *in_keycode)
{
	t_internal_context	*context;
	t_buffer			keycode;
	t_list				*pos;
	t_node_key			*key;

	if (in_keycode_size == 0 || in_keycode == NULL)
		return (false);
	keycode.size = in_keycode_size;
	keycode.bytes = (char *)in_keycode;
	caps__get_context(&context);
	LIST_FOREACH(&context->key_head, pos)
	{
		key = CONTAINER_OF(pos, t_node_key, list);
		if (!caps__keycode_cmp(keycode, key->keycode))
			return (true);
	}
	return (false);
}
