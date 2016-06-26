#include <termcap.h>
#include "internal_caps.h"
#include "types.h"

bool	caps__init_func_by_keycode(const t_buffer keycode, int (*func)())
{
	t_internal_context	*context;
	t_list				*new_key;

	if (keycode.bytes == NULL || func == NULL)
		return (FALSE);
	caps__get_context(&context);
	new_key = node_key__create(keycode.size, keycode.bytes, func);
	if (!new_key)
		return (FALSE);
	list_push_back(new_key, &context->key_head);
	return (TRUE);
}
