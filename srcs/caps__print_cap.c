#include "internal_caps.h"
#include "types.h"
#include "log.h"

void				caps__print_cap(const t_caps_cap value)
{
	t_internal_context	*context;

	caps__get_context(&context);
	caps__print(42, context->caps[value]);
}
