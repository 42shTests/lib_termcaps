#include "internal_caps.h"
#include "types.h"

void				caps__print_cap(const t_caps_cap value, int lines)
{
	t_internal_context	*context;

	caps__get_context(&context);
	caps__print(context->caps[value], lines);
}
