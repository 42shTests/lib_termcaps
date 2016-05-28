/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps__init_func_by_keycode.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:50:07 by abombard          #+#    #+#             */
/*   Updated: 2016/05/26 13:02:33 by abombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_caps.h"
#include "types.h"


#include <termcap.h>

bool	caps__init_func_by_keycode(const t_buffer in_keycode, int (*in_func)())
{
	t_internal_context	*context;
	size_t				i;

	if (in_keycode.size == 0 || !in_keycode.bytes)
	{
		log_fatal("in_keycode.size %zu in_keycode.bytes %p", in_keycode.size, (void *)in_keycode.bytes);
		return 0;
	}
	caps__get_context(&context);
	i = 0;
	while (i < context->map_size)
	{
		if (!caps__keycode_cmp(in_keycode, context->map[i].keycode))
		{
			context->map[i].func = in_func;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
