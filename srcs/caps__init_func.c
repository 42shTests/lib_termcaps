#include "internal_caps.h"
#include "types.h"
#include "libft.h"
#include <termcap.h>

bool	caps__init_func(char *tcapcode, int (*func)())
{
	t_internal_context	*context;
	char				*keycode;
	t_list				*new_key;

	if (!tcapcode || !func)
		return (false);
	caps__get_context(&context);
	keycode = tgetstr(tcapcode, &context->buffaddr);
	if (!keycode)
		return (false);
	new_key = node_key__create(ft_strlen(keycode), keycode, func);
	if (!new_key)
		return (NULL);
	list_push_back(new_key, &context->key_head);
	return (true);
}
