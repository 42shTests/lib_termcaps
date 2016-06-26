#include "internal_caps.h"
#include "types.h"
#include "context.h"

void	caps__get_context(t_internal_context **out_context)
{
	*out_context = &g_internal_context;
}
