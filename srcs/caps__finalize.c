#include "internal_caps.h"
#include "types.h"

bool	caps__finalize(void)
{
	t_internal_context	*context;

	caps__get_context(&context);
	list_key__destroy(&context->key_head);
	return (TRUE);
}
