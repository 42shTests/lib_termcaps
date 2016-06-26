#include "types.h"

#include "internal_caps.h"

bool	caps__exec_func(const size_t in_keycode_size,
						const char *in_keycode,
						void *in_context)
{
	t_internal_context	*context;
	t_buffer			keycode;
	t_list				*pos;
	t_node_key			*key;

	keycode.size = in_keycode_size;
	keycode.bytes = (char *)in_keycode;
	caps__get_context(&context);
	pos = &context->key_head;
	while ((pos = pos->next) && pos != &context->key_head)
	{
		key = CONTAINER_OF(pos, t_node_key, list);
		if (!caps__keycode_cmp(keycode, key->keycode))
		{
			return (key->func(in_context));
		}
	}
	return (false);
}
